#include "ft_printf.h"

char *padd_s(t_form *f, long long *len, long long *padd)
{
	char *buf;

	*padd = 0;
	if (f->precision >= 0 && f->precision < *len)
	{
		*len = f->precision;
		if (f->precision < f->width)
			*padd = f->width - f->precision;
	}
	else if (*len < f->width)
		*padd = f->width - *len;
	if (!(buf = (char *)ft_calloc(*padd + 1, sizeof(char))))
		return (NULL);
	ft_memset(buf, 32, *padd);
	return (buf);
}

int print_type_s(t_form *f, va_list ap)
{
	char *c;
	long long len;
	long long padd;
	char *s;

	c = va_arg(ap, char *);
	len = ft_strlen(c);
	if (!(s = padd_s(f, &len, &padd)))
		return (0);
	if (f->flag & ((char)1 << 7))
	{
		f->size += write(f->fd, c, len);
		f->size += write(f->fd, s, padd);
		return (1);
	}
	else if (f->flag & ((char)1 << 4))
		ft_memset(s, 48, padd);
	f->size += write(f->fd, s, padd);
	f->size += write(f->fd, c, len);
	free_ptr((void *)(&s));
	return (1);
}
