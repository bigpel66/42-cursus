#include "ft_printf.h"

int	parse_check(const char *format, va_list ap)
{
	int		bytes;
	t_form	*f;

	bytes = 0;
	f = NULL;
	if (!(f = form_create(f)))
		return (-1);
	f->fd = 1;
	if (!(ft_strchr(format, '%')))
		bytes = write(f->fd, format, ft_strlen(format));
	else
		bytes = parse_format(f, format, ap);
	free_unit_ptr((void *)(&f));
	return (bytes);
}
