#include "ft_printf.h"

char *get_hex(t_form *f, unsigned long long val, int capital)
{
	int shift;
	int offset;
	int i;
	char *buf;

	f->dig = 1;
	shift = sizeof(void *) * 2;
	offset = shift;
	if (!(buf = (char *)ft_calloc(offset + 1, sizeof(char))))
		return (NULL);
	while (--shift >= 0)
	{
		i = (val & (unsigned long long)15 << (shift * 4)) >> (shift * 4);
		if (capital)
			buf[offset - (shift + 1)] = "0123456789ABCDEF"[i];
		else
			buf[offset - (shift + 1)] = "0123456789abcdef"[i];
		if (f->dig == 1 && i)
			f->dig = shift + 1;
	}
	if (f->flg & 4 && f->prec == 0 && val == 0)
		f->dig = 0;
	return (buf);
}
