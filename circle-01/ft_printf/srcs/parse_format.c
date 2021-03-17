#include "ft_printf.h"

int parse_format(t_form *f, const char *format, va_list ap)
{
	char *tmp;
	long long diff;

	while (*format)
	{
		tmp = ft_strchr(format, '%');
		diff = (long long)(tmp - format);
		if (tmp)
			f->size += write(f->fd, format, diff);
		else
		{
			f->size += write(f->fd, format, ft_strlen(format));
			break;
		}
		form_read(f, tmp, ap);
		if (!is_error(f) && !(f->flg & 1))
			form_write(f, ap);
		if (is_error(f) || f->i == -1)
			return (-1);
		diff += (f->i);
		format += diff;
		form_init(f);
	}
	return (f->size);
}
