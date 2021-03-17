#include "ft_printf.h"

int allocate_with_dot(t_form *f, char **p, char **s, int padd)
{
	long long val;
	long long p_len;
	long long s_len;

	val = f->dig;
	p_len = 0;
	s_len = 0;
	if (f->dig < f->prec)
	{
		val = f->prec;
		s_len = f->prec - f->dig;
	}
	if (val + padd < f->width)
		p_len = f->width - (val + padd);
	*p = (char *)ft_calloc(p_len + 1, sizeof(char));
	*s = (char *)ft_calloc(s_len + 1, sizeof(char));
	if (!(*p && *s))
		return (0);
	ft_memset(*p, 32, p_len);
	if (f->prec == -2 && !(f->flg & 128) && f->flg & 16)
		ft_memset(*p, 48, p_len);
	ft_memset(*s, 48, s_len);
	return (1);
}
