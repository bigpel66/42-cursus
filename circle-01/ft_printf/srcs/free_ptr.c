#include "ft_printf.h"

void	free_ptr(void **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}
