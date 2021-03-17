#include "ft_printf.h"

void	process_dot(t_form *f, const char *format, va_list ap)
{
	if (format[f->i] == '*')
	{
		++(f->i);
		f->prec = va_arg(ap, int);
		if (f->prec < 0)
			f->prec = -2;
		else if (f->prec == 2147483647)
			f->prec = -1;
	}
	else if (is_digit(format[f->i]))
		f->prec = get_precision(f, format);
}
