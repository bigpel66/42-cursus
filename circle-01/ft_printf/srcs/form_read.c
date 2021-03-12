#include "ft_printf.h"

void form_read(t_form *f, const char *format, va_list ap)
{
	++(f->i);
	while (1)
	{
		if (is_flag(format[f->i]))
			get_flag(f, format, ap);
		else if (is_digit(format[f->i]))
			f->width = get_width(f, format);
		else if (is_length(format[f->i]))
			get_length(f, format);
		else if (is_type(format[f->i]))
		{
			f->type = get_index("cspdiuxX%nfge", format[(f->i)++]);
			break;
		}
		else
		{
			f->flag |= 1;
			break;
		}
	}
}
