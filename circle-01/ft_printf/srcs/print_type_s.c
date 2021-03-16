#include "ft_printf.h"

char *padd_s(t_form *f, long long *len, long long *p_len)
{
	char *buf;

	*p_len = 0;
	if (f->precision >= 0 && f->precision < *len)
	{
		*len = f->precision;
		if (f->precision < f->width)
			*p_len = f->width - f->precision;
	}
	else if (*len < f->width)
		*p_len = f->width - *len;
	if (!(buf = (char *)ft_calloc(*p_len + 1, sizeof(char))))
		return (NULL);
	ft_memset(buf, 32, *p_len);
	return (buf);
}

int print_type_s(t_form *f, char *s)
{
	long long len;
	char *padd;
	long long p_len;

	len = ft_strlen(s);
	if (!(padd = padd_s(f, &len, &p_len)))
		return (0);
	if (f->flag & ((char)1 << 7))
	{
		f->size += write(f->fd, s, len);
		f->size += write(f->fd, padd, p_len);
		return (1);
	}
	else if (f->flag & ((char)1 << 4))
		ft_memset(padd, 48, p_len);
	f->size += write(f->fd, padd, p_len);
	f->size += write(f->fd, s, len);
	free_ptr((void *)(&padd));
	return (1);
}
