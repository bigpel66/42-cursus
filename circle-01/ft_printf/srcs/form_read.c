#include "ft_printf.h"

void form_read(t_form *f, const char *format, va_list ap)
{
	++(f->i);
	while (1)
	{
		if (check_flag(format[f->i]))
			process_flag(f, format, ap);
		else if (check_digit(format[f->i]))
			process_width(f, format);
		else if (check_length(format[f->i]))
			process_length(f, format);
		else if (check_type(format[f->i]))
		{
			process_type(f, format);
			break;
		}
		else
		{
			f->flag |= 1;
			break;
		}
	}
}
