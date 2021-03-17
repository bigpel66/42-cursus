#include "ft_printf.h"

int process_number(t_form *f, va_list ap)
{
	int code;

	code = 0;
	if (f->type == 4 || f->type == 5)
		code = print_decimal(f, (long long)(va_arg(ap, int)), 1);
	else if (f->type == 6)
		code = print_decimal(f, (long long)(va_arg(ap, unsigned int)), 0);
	else if (f->type == 7)
		code = print_hexadecimal(f, va_arg(ap, unsigned int), 0);
	else if (f->type == 8)
		code = print_hexadecimal(f, va_arg(ap, unsigned int), 1);
	return (code);
}
