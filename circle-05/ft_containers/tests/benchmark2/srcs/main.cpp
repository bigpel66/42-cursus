#include "./includes/UnitTester.hpp"
#include <iostream>

#ifdef BENCH
void end(void)__attribute__((destructor));

void end(void)
{
    system("leaks -q bench");
}
#endif

int main(int ac, char** av)
{
	std::cout << "\033[1;94m" <<
	 	"# ****************************************************************************** #\n"
	 	"#                                                                                #\n"
	 	"#                              containers bench test2                            #\n"
	 	"#                                                                                #\n"
	 	"# ****************************************************************************** #\n"
	 	 	 	 	 	<< "\033[0m" << std::endl;
	int        status;
	UnitTester test;
	test.load_tests(ac, av);
#ifdef BENCH
	status = test.run_bench_tests();
#else
	status = test.run_tests();
#endif
	return (status);
}
