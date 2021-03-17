#include "ft_printf.h"

void	get_length(t_form *f, const char *format)
{
	int	opt;

	f->len = get_index("lh", format[(f->i)++]);
	opt = get_index("lh", format[f->i]);
	if (f->len == opt)
	{
		++(f->i);
		f->len += 2;
	}
}
