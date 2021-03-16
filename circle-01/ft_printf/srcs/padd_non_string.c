#include "ft_printf.h"

int padd_non_string(t_form *f, char **pref, char **suff, int padd)
{
	int ret;

	if (f->flag & 4)
		ret = allocate_with_dot(f, pref, suff, padd);
	else
		ret = allocate_without_dot(f, pref, suff, padd);
	if (!ret)
		return (0);
	return (1);
}
