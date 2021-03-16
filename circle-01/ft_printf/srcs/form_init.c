#include "ft_printf.h"

void form_init(t_form *f)
{
	f->i = 0;
	f->flag = 0;
	f->width = 0;
	f->precision = 0;
	f->length = 0;
	f->type = 0;
	f->digit = 0;
}
