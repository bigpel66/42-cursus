#include "ft_printf.h"

int allocate_with_dot(t_form *f, int padd)
{
	long long val;

	val = f->dig;
	f->p_len = 0;
	f->s_len = 0;
	if (f->dig < f->prec)
	{
		val = f->prec;
		f->s_len = f->prec - f->dig;
	}
	if (val + padd < f->width)
		f->p_len = f->width - (val + padd);
	f->p = (char *)ft_calloc(f->p_len + 1, sizeof(char));
	f->s = (char *)ft_calloc(f->s_len + 1, sizeof(char));
	if (!(f->p && f->s))
		return (0);
	ft_memset(f->p, 32, f->p_len);
	if (f->prec == -2 && !(f->flg & 128) && f->flg & 16)
	{
		swap_ptr(f);
		ft_memset(f->p, 48, f->p_len);
	}
	ft_memset(f->s, 48, f->s_len);
	return (1);
}
