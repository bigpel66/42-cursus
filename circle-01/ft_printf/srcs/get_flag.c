#include "ft_printf.h"

void	get_flag(t_form *f, const char *format, va_list ap)
{
	int	opt;

	opt = get_index("*.#0 +-", format[(f->i)++]);
	f->flg |= (1 << opt);
	if (opt == 1)
		process_asterisk(f, ap);
	else if (opt == 2)
		process_dot(f, format, ap);
}
