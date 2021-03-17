#include "ft_printf.h"

void form_init(t_form *f)
{
	f->i = 0;
	f->dig = 0;
	f->flg = 0;
	f->width = 0;
	f->prec = 0;
	f->length = 0;
	f->t = 0;
	f->p_len = 0;
	f->s_len = 0;
	// if (f->p)
		// free(f->p);
	f->p = NULL;
	// if (f->s)
		// free(f->s);
	f->s = NULL;
}
