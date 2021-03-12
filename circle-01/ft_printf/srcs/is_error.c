#include "ft_printf.h"

int is_error(t_form *f)
{
	if (f->width == -1 || f->precision == -1)
	{
		return (1);
	}
	return (0);
}
