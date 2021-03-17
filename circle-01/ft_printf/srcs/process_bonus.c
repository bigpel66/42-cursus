#include "ft_printf.h"

int process_bonus(t_form *f, va_list ap)
{
	int test1;
	int test2;
	test1 = f->flg & 0;
	test2 = va_arg(ap, int);
	return (1);
}
