#include "ft_printf.h"

int get_padd(t_form *f, size_t *len)
{
	if (f->precision >= 0 && f->precision < *len)
	{
		*len = f->precision;
		if (f->precision < f->width)
			return (f->width - f->precision);
	}
	else if (*len < f->width)
		return (f->width - *len);
	return (0);
}

int print_type_s(t_form *f, va_list ap)
{
	char *c;
	size_t len;
	int padd;
	char *s;

	c = va_arg(ap, char *);
	len = ft_strlen(c);
	padd = get_padd(f, &len);
	if (!(s = (char *)malloc(padd)))
		return (0);
	ft_memset(s, 32, padd);
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
