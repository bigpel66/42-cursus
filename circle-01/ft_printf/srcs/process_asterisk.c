#include "ft_printf.h"

void process_asterisk(t_form *f, va_list ap)
{
	f->width = va_arg(ap, int);

	if (f->width >= -2147483646 && f->width <= 2147483646)
	{
		if (f->width < 0)
		{
			f->flg |= (1 << 7);
			f->width = ~(f->width) + 1;
		}
	}
	else
		f->width = -1;
}
