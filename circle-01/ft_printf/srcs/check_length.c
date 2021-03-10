#include "ft_printf.h"

int check_length(const char *c)
{
	if (*c)
	{
		if (*c == 'l')
		{
			++c;
			if (*c && *c == 'l')
				return (2);
			return (1);
		}
		else if (*c == 'h')
		{
			++c;
			if (*c && *c == 'h')
				return (4);
			return (3);
		}
	}
	return (0);
}
