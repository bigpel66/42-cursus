#include "ft_printf.h"

long long	get_precision(t_form *f, const char *format)
{
	long long	ret;
	long long	max;

	ret = (format[(f->i)++]) - '0';
	max = ((long long)1 << 32);
	while (is_digit(format[f->i]))
	{
		ret = ret * 10 + (format[(f->i)++] - '0');
		if (ret >= 2147483648)
			ret -= max;
	}
	if (ret == 2147483647)
		return (-1);
	else if (ret >= -2147483646 && ret <= -1)
		return (-2);
	else if (ret == -2147483648 || ret == -2147483647)
		ret += max;
	return (ret);
}
