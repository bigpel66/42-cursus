#include "ft_printf.h"

int	is_type(int c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
			c == 'u' || c == 'x' || c == 'X' || c == '%' || c == 'n' ||
			c == 'f' || c == 'g' || c == 'e');
}
