#include "../includes/Server.hpp"
#include "../includes/Logger.hpp"
#include "../includes/Engine.hpp"

#include <pthread.h>

struct Worker {
  Server *serv_;
  int id_;
  pthread_t thr_;
};

std::vector<Worker> g_workers;

void *startWorker(void *arg) {
  Server *serv = ((Worker*)arg)->serv_;
  int id = ((Worker*)arg)->id_;
  serv->run(id);
  return NULL;
}

int main(int argc, char **argv) {
  try {
    Engine e(argc, argv);
    Server serv(e.get_parser()->get_serv_contexts());
    serv.init();
    if (e.get_parser()->get_worker_count() > 0) {
      g_workers.resize(e.get_parser()->get_worker_count());
      for (std::size_t i = 0; i < e.get_parser()->get_worker_count(); i++) {
        g_workers[i].id_ = i + 1;
        g_workers[i].serv_ = new Server(serv);
        pthread_create(&g_workers[i].thr_, NULL, startWorker, &g_workers[i]);
        usleep(500);
      }
      for (std::size_t i = 0; i < e.get_parser()->get_worker_count(); i++) {
        pthread_join(g_workers[i].thr_, NULL);
        delete g_workers[i].serv_;
      }
    } else {
      serv.run();
    }
  }
  catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  exit(1);
}
