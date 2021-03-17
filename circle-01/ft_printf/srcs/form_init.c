#include "ft_printf.h"

void	form_init(t_form *f)
{
	f->i = 0;
	f->dig = 0;
	f->flg = 0;
	f->width = 0;
	f->prec = 0;
	f->len = 0;
	f->t = 0;
}
