#include "ft_printf.h"

char *padd_str(t_form *f, int string)
{
	char *buf;

	f->p_len = 0;
	if (string && (f->flg & 4) && f->prec >= 0 && f->prec < f->dig)
	{
		f->dig = f->prec;
		if (f->prec < f->width)
			f->p_len = f->width - f->prec;
	}
	else if (f->dig < f->width)
		f->p_len = f->width - f->dig;
	if (!(buf = (char *)ft_calloc(f->p_len + 1, sizeof(char))))
		return (NULL);
	ft_memset(buf, 32, f->p_len);
	return (buf);
}
