#include "ft_printf.h"

char *padd_string(t_form *f, long long *p_len, int string)
{
	char *buf;

	*p_len = 0;
	if (string && f->precision >= 0 && f->precision < f->digit)
	{
		f->digit = f->precision;
		if (f->precision < f->width)
			*p_len = f->width - f->precision;
	}
	else if (f->digit < f->width)
		*p_len = f->width - f->digit;
	if (!(buf = (char *)ft_calloc(*p_len + 1, sizeof(char))))
		return (NULL);
	ft_memset(buf, 32, *p_len);
	return (buf);
}
