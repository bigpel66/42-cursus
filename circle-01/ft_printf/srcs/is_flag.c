#include "ft_printf.h"

int is_flag(int c)
{
	return (c == '-' || c == '+' || c == ' ' || c == '0' || c == '#' || c == '.' || c == '*');
}
