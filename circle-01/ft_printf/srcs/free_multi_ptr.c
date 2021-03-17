#include "ft_printf.h"

void free_multi_ptr(void **optr, void **pptr, void **sptr)
{
	if (*optr)
		free(*optr);
	*optr = NULL;
	if (*pptr)
		free(*pptr);
	*pptr = NULL;
	if (*sptr)
		free(*sptr);
	*sptr = NULL;
}
