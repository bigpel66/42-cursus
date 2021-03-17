#include "ft_printf.h"

int	is_error(t_form *f)
{
	if (f->width == -1 || f->prec == -1)
	{
		return (1);
	}
	return (0);
}
