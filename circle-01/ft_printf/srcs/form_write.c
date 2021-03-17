#include "ft_printf.h"

void form_write(t_form *f, va_list ap)
{
	int code;

	code = 0;
	if (f->type == 1 || f->type == 2 || f->type == 9)
		code = process_string(f, ap);
	else if (f->type == 3)
		code = print_hexadecimal(f, (unsigned long long)(va_arg(ap, void *)), 0);
	else if (f->type >= 4 && f->type <= 8)
		code = process_number(f, ap);
	else if (f->type >= 10 && f->type <= 13)
		code = process_bonus(f, ap);
	if (!code)
		f->i = -1;
}
