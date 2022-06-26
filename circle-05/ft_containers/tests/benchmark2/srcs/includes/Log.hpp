#ifndef LOG_HPP
#define LOG_HPP

#include <fstream>
#include <string>

#define get_func_name(x) (char*)#x

typedef struct s_unit_subtests t_unit_subtests;

class Log
{
  private:
	static const std::string k_logfile;

	std::ofstream _logfile_stream;

  public:
	static std::string _current_explanation;
	static void        set_explanation(std::string explanation);

	Log();
	~Log();

	void write_to_logfile(t_unit_subtests& current_test);

  private:
	void _open_logfile();

	Log(Log const& other);
	Log& operator=(Log const& other);
};

#endif /* LOG_HPP */
