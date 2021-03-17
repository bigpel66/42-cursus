#include "ft_printf.h"

int	get_index(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
		if (s[i++] == c)
			return (i);
	return (0);
}
