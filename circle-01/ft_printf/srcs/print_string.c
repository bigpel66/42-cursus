#include "ft_printf.h"

int print_string(t_form *f, char *s, int string)
{
	char *padd;
	long long p_len;

	f->digit = ft_strlen(s);
	if (!(padd = padd_string(f, &p_len, string)))
		return (0);
	if (f->flag & 128)
	{
		f->size += write(f->fd, s, f->digit);
		f->size += write(f->fd, padd, p_len);
		return (1);
	}
	else if (f->flag & 16)
		ft_memset(padd, 48, p_len);
	f->size += write(f->fd, padd, p_len);
	f->size += write(f->fd, s, f->digit);
	free_ptr((void *)(&padd));
	return (1);
}
