#include "ft_printf.h"

void get_length(t_form *f, const char *format)
{
	int opt;

	f->length = get_index("lh", format[(f->i)++]);
	opt = get_index("lh", format[f->i]);
	if (f->length == opt)
	{
		++(f->i);
		f->length += 2;
	}
}
