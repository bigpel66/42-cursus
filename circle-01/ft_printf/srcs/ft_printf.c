#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		ret;
	va_list	ap;

	va_start(ap, format);
	ret = parse_check(format, ap);
	va_end(ap);
	return (ret);
}
