#include "ft_printf.h"

char *get_dec(t_form *f, long long val)
{
	long long tmp;
	long long i;
	char *buf;

	f->dig = 1;
	tmp = val / 10;
	while (tmp && ++(f->dig))
		tmp /= 10;
	i = f->dig;
	if (val < 0)
		val = ~(val) + 1;
	if (!(buf = (char *)ft_calloc(i + 1, sizeof(char))))
		return (NULL);
	while (1)
	{
		buf[--i] = "0123456789"[val % 10];
		if (!(val /= 10))
			break;
	}
	if (f->flg & 4 && f->prec == 0 && val == 0)
		f->dig = 0;
	return (buf);
}
