#include "ft_printf.h"

char *padd_c(t_form *f, long long *p_len)
{
	char *buf;

	*p_len = 0;
	if (f->width >= 2)
		*p_len = f->width - 1;
	if (!(buf = (char *)ft_calloc(*p_len + 1, sizeof(char))))
		return (NULL);
	ft_memset(buf, 32, *p_len);
	return (buf);
}

int print_type_c(t_form *f, char c)
{
	long long p_len;
	char *padd;

	if (!(padd = padd_c(f, &p_len)))
		return (0);
	if (f->flag & 128)
	{
		f->size += write(f->fd, &c, 1);
		f->size += write(f->fd, padd, p_len);
		return (1);
	}
	else if (f->flag & 16)
		ft_memset(padd, 48, p_len);
	f->size += write(f->fd, padd, p_len);
	f->size += write(f->fd, &c, 1);
	free_ptr((void *)(&padd));
	return (1);
}
