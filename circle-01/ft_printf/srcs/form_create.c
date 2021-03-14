#include "ft_printf.h"

t_form *form_create(t_form *f)
{
	if (!(f = (t_form *)ft_calloc(1, sizeof(t_form))))
		return (NULL);
	return (f);
}
