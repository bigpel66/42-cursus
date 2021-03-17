#include "ft_printf.h"

char *get_hexadecimal(t_form *f, unsigned long long val, int capital)
{
	int shift;
	int offset;
	int i;
	char *buf;

	f->digit = 0;
	shift = sizeof(void *) * 2;
	offset = shift++;
	if (!(buf = (char *)ft_calloc(shift, sizeof(char))))
		return (NULL);
	while (--shift)
	{
		i = (val & (unsigned long long)15 << ((shift - 1) * 4)) >> ((shift - 1) * 4);
		if (capital)
			buf[offset - shift] = "0123456789ABCDEF"[i];
		else
			buf[offset - shift] = "0123456789abcdef"[i];
		if (!f->digit && i)
			f->digit = shift;
	}
	return (buf);
}
