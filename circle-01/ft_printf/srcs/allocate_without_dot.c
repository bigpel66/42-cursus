#include "ft_printf.h"

int allocate_without_dot(t_form *f, char **p, char **s, int padd)
{
	char **tmp;
	long long p_len;
	long long s_len;

	tmp = NULL;
	p_len = 0;
	s_len = 0;
	if (f->dig + padd < f->width)
		p_len = f->width - (f->dig + padd);
	*p = (char *)ft_calloc(p_len + 1, sizeof(char));
	*s = (char *)ft_calloc(s_len + 1, sizeof(char));
	if (!(*p && *s))
		return (0);
	if (f->flg & 16 && !(f->flg & 128))
	{
		tmp = p;
		p = s;
		s = tmp;
	}
	ft_memset(*p, 32, p_len);
	if (!(f->flg & 128) && f->flg & 16)
		ft_memset(*p, 48, p_len);
	ft_memset(*s, 48, s_len);
	return (1);
}
