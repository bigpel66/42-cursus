#include "ft_printf.h"

int process_decimal(t_form *f, va_list ap)
{
	int code;

	code = 0;
	if (f->type == 4)
		code = print_type_d(f, ap);
	else if (f->type == 5)
		code = print_type_i(f, ap);
	else if (f->type == 6)
		code = print_type_u(f, ap);
	else if (f->type == 7)
		code = print_type_x(f, ap, 0);
	else if (f->type == 8)
		code = print_type_x(f, ap, 1);
	if (!code)
		return (0);
	return (1);
}
