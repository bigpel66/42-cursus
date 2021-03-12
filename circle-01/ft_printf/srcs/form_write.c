#include "ft_printf.h"

void form_write(t_form *f, const char *format, va_list ap)
{
	int code;

	if (f->type == 1)
		code = print_type_c(f, ap);
	else if (f->type == 2)
		code = print_type_s(f, ap);
	else if (f->type == 3)
		code = print_type_p(f, ap);
	else if (f->type >= 4 && f->type <= 8)
		code = process_decimal(f, ap);
	else if (f->type == 9)
		code = print_type_tag(f, ap);
	else if (f->type >= 10 && f->type <= 13)
		code = process_bonus(f, ap);
	if (!code)
		f->i = -1;
}
