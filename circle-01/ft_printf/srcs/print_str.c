#include "ft_printf.h"

int print_str(t_form *f, char *s, int string)
{
	if (!s)
		if (!(s = allocate_null_str()))
			return (0);
	f->dig = 1;
	if (string)
		f->dig = ft_strlen(s);
	if (!(f->p = padd_str(f, string)))
		return (0);
	if (f->flg & 128)
	{
		f->size += write(f->fd, s, f->dig);
		f->size += write(f->fd, f->p, f->p_len);
		return (1);
	}
	else if (f->flg & 16)
		ft_memset(f->p, 48, f->p_len);
	f->size += write(f->fd, f->p, f->p_len);
	f->size += write(f->fd, s, f->dig);
	return (1);
}
