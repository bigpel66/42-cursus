#include "ft_printf.h"

char *get_number(t_form *f, long long val, int base)
{
	long long tmp;
	long long i;
	char *buf;

	tmp = val;
	f->digit = 0;
	while (tmp && ++(f->digit))
		tmp /= base;
	i = f->digit;
	if (val < 0)
		val = ~(val) + 1;
	if (!(buf = (char *)ft_calloc(i + 1, sizeof(char))))
		return (NULL);
	while (val)
	{
		buf[--i] = "0123456789abcdef"[val % base];
		val /= base;
	}
	return (buf);
}
