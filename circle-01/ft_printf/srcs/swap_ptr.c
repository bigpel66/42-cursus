#include "ft_printf.h"

void swap_ptr(t_form *f)
{
	char *tmp;
	long long len;

	tmp = f->p;
	f->p = f->s;
	f->s = tmp;
	len = f->p_len;
	f->p_len = f->s_len;
	f->s_len = len;
}
