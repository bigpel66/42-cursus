#include "ft_printf.h"

t_form *form_create(t_form *f)
{
	if (!(f = (t_form *)malloc(sizeof(t_form))))
		return (NULL);
	ft_memset(f, 0, sizeof(t_form));
	return (f);
}
