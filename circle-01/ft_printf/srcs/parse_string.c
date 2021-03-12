#include "ft_printf.h"

int parse_string(t_form *f, const char *format, va_list ap)
{
	size_t diff;
	char *tmp;

	while (*format)
	{
		tmp = ft_strchr(format, '%');
		diff = (size_t)(tmp - format);
		f->size += write(f->fd, format, diff);
		form_read(f, tmp, ap);
		if (is_error(f))
			return (-1);
		if (!(f->flag & 1))
			form_write(f, tmp, ap);
		diff += (f->i);
		format += diff;
		form_init(f);
	}
	return (f->size);
}
