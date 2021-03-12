#include "ft_printf.h"

void process_dot(t_form *f, const char *format, va_list ap)
{
	if (format[f->i] == '*')
	{
		++(f->i);
		f->precision = va_arg(ap, int);
		if (f->precision < 0)
			f->precision = -2;
		else if (f->precision == 2147483647)
			f->precision = -1;
	}
	else if (is_digit(format[f->i]))
		f->precision = get_precision(f, format);
}
