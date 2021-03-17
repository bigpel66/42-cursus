#include "ft_printf.h"

int process_str(t_form *f, va_list ap)
{
	int code;
	char *s;

	code = 0;
	s = NULL;
	if (f->t == 1 || f->t == 9)
	{
		if (!(s = (char *)ft_calloc(2, sizeof(char))))
			return (code);
		s[0] = '%';
		if (f->t == 1)
			s[0] = va_arg(ap, int);
		code = print_str(f, s, 0);
		free_ptr((void *)(&s));
	}
	else if (f->t == 2)
		code = print_str(f, va_arg(ap, char *), 1);
	return (code);
}
