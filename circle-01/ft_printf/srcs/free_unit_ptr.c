#include "ft_printf.h"

void	free_unit_ptr(void **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}
