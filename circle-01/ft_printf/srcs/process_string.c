#include "ft_printf.h"

int process_string(t_form *f, va_list ap)
{
	int code;
	char *s;

	code = 0;
	s = NULL;
	if (f->type == 1 || f->type == 9)
	{
		if (!(s = (char *)ft_calloc(2, sizeof(char))))
			return (code);
		s[0] = '%';
		if (f->type == 1)
			s[0] = va_arg(ap, int);
		code = print_string(f, s, 0);
		free_ptr((void *)(&s));
	}
	else if (f->type == 2)
		code = print_string(f, va_arg(ap, char *), 1);
	return (code);
}
