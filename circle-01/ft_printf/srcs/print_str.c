#include "ft_printf.h"

int print_str(t_form *f, char *s, int string)
{
	char *padd;
	long long p_len;

	if (!s)
		if (!(s = allocate_null_str()))
			return (0);
	f->dig = 1;
	if (string)
		f->dig = ft_strlen(s);
	if (!(padd = padd_str(f, &p_len, string)))
		return (0);
	if (f->flg & 128)
	{
		f->size += write(f->fd, s, f->dig);
		f->size += write(f->fd, padd, p_len);
		return (1);
	}
	else if (f->flg & 16)
		ft_memset(padd, 48, p_len);
	f->size += write(f->fd, padd, p_len);
	f->size += write(f->fd, s, f->dig);
	free_unit_ptr((void *)(&padd));
	return (1);
}
