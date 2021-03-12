#include "ft_printf.h"

int print_type_c(t_form *f, va_list ap)
{
	char c;
	int padd;
	char *s;

	c = va_arg(ap, int);
	padd = 0;
	if (f->width >= 2)
		padd = f->width - 1;
	if (!(s = (char *)malloc(padd)))
		return (0);
	ft_memset(s, 32, padd);
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
