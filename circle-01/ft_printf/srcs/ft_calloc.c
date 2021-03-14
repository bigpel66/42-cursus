#include "ft_printf.h"

void *ft_calloc(size_t cnt, size_t n)
{
	void *buf;

	if (!(buf = (void *)malloc(cnt * n)))
		return (NULL);
	ft_memset(buf, 0, cnt * n);
	return (buf);
}
