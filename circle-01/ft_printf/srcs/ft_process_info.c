#include "ft_printf.h"

void	ft_process_info(t_info *i, const char *format)
{
	++(i->size);
	++format;
	ft_process_flag(i, format);
	ft_process_width(i, format);
	ft_process_precision(i, format);
	ft_process_length(i, format);
}
