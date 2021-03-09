#include "ft_printf.h"

int	ft_process_string(t_info *i, const char *format, va_list ap)
{
	size_t	diff;
	char	*tmp;

	while (*format)
	{
		tmp = ft_strchr(format, '%');
		diff = (size_t)(tmp - format);
		i->bytes += write(i->fd, format, diff);
		ft_process_info(i, tmp);
		if (i->size == -1)
			return (-1);
		ft_process_print(i, tmp, ap);
		diff += (i->size);
		format += diff;
		ft_init_info(i);
	}
	return (i->bytes);
}
