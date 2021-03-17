#include "ft_printf.h"

int padd_non_str(t_form *f, char **p, char **s, int padd)
{
	int ret;

	if (f->flg & 4)
		ret = allocate_with_dot(f, p, s, padd);
	else
		ret = allocate_without_dot(f, p, s, padd);
	if (!ret)
		return (0);
	return (1);
}
