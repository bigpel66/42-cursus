#include "ft_printf.h"

char *get_decimal(t_form *f, long long val)
{
	long long tmp;
	long long i;
	char *buf;

	tmp = val;
	f->digit = 0;
	while (tmp && ++(f->digit))
		tmp /= 10;
	i = f->digit;
	if (val < 0)
		val = ~(val) + 1;
	if (!(buf = (char *)ft_calloc(i + 1, sizeof(char))))
		return (NULL);
	while (val)
	{
		buf[--i] = "0123456789"[val % 10];
		val /= 10;
	}
	return (buf);
}
