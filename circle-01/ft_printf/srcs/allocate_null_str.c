#include "ft_printf.h"

char *allocate_null_str(void)
{
	char *buf;

	if (!(buf = (char *)ft_calloc(7, sizeof(char))))
		return (NULL);
	buf[0] = '(';
	buf[1] = 'n';
	buf[2] = 'u';
	buf[3] = 'l';
	buf[4] = 'l';
	buf[5] = ')';
	return (buf);
}
