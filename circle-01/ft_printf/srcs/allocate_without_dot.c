#include "ft_printf.h"

int allocate_without_dot(t_form *f, char **pref, char **suff, int padd)
{
	char *tmp;
	long long p_len;
	long long s_len;

	tmp = NULL;
	p_len = 0;
	s_len = 0;
	if (f->digit + padd < f->width)
		p_len = f->width - (f->digit + padd);
	*suff = (char *)ft_calloc(s_len + 1, sizeof(char));
	*pref = (char *)ft_calloc(p_len + 1, sizeof(char));
	if (!(*pref && *suff))
		return (0);
	if (f->flag & ((char)1 << 4))
	{
		tmp = *pref;
		*pref = *suff;
		*suff = tmp;
	}
	ft_memset(*pref, 32, p_len);
	ft_memset(*suff, 48, s_len);
	return (1);
}
