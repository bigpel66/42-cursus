#include "ft_printf.h"

int process_nbr(t_form *f, va_list ap)
{
	int code;

	code = 0;
	if (f->t == 4 || f->t == 5)
		code = print_dec(f, (long long)(va_arg(ap, int)), 1);
	else if (f->t == 6)
		code = print_dec(f, (long long)(va_arg(ap, unsigned int)), 0);
	else if (f->t == 7)
		code = print_hex(f, va_arg(ap, unsigned int), 0, 0);
	else if (f->t == 8)
		code = print_hex(f, va_arg(ap, unsigned int), 1, 0);
	return (code);
}
