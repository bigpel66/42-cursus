#include "ft_printf.h"

char *padd_c(t_form *f, long long *padd)
{
	char *buf;

	*padd = 0;
	if (f->width >= 2)
		*padd = f->width - 1;
	if (!(buf = (char *)ft_calloc(*padd + 1, sizeof(char))))
		return (NULL);
	ft_memset(buf, 32, *padd);
	return (buf);
}

int print_type_c(t_form *f, va_list ap, int tag)
{
	char c;
	long long padd;
	char *s;

	if (tag)
		c = '%';
	else
		c = va_arg(ap, int);
	if (!(s = padd_c(f, &padd)))
		return (0);
	if (f->flag & ((char)1 << 7))
	{
		f->size += write(f->fd, &c, 1);
		f->size += write(f->fd, s, padd);
		return (1);
	}
	else if (f->flag & ((char)1 << 4))
		ft_memset(s, 48, padd);
	f->size += write(f->fd, s, padd);
	f->size += write(f->fd, &c, 1);
	free_ptr((void *)(&s));
	return (1);
}
