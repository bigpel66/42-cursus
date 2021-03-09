#include "ft_printf.h"

void	ft_init_info(t_info *i)
{
	i->size = 0;
	i->minus = 0;
	i->zero = 0;
	i->dot = 0;
	i->star = 0;
	i->plus = 0;
	i->space = 0;
	i->hash = 0;
	i->width = 0;
	i->precision = 0;
	i->length = 0;
}
