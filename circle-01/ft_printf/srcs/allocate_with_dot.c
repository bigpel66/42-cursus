#include "ft_printf.h"

int allocate_with_dot(t_form *f, char **pref, char **suff, int padd)
{
	long long val;
	long long p_len;
	long long s_len;

	val = f->digit;
	p_len = 0;
	s_len = 0;
	if (f->digit < f->precision)
	{
		val = f->precision;
		s_len = f->precision - f->digit;
	}
	if (val + padd < f->width)
		p_len = f->width - (val + padd);
	*pref = (char *)ft_calloc(p_len + 1, sizeof(char));
	*suff = (char *)ft_calloc(s_len + 1, sizeof(char));
	if (!(*pref && *suff))
		return (0);
	ft_memset(*pref, 32, p_len);
	ft_memset(*suff, 48, s_len);
	return (1);
}
