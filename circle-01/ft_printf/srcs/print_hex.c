#include "ft_printf.h"

int print_hex(t_form *f, unsigned long long val, int capital, int adr)
{
	int pred;
	char *hex;

	pred = (f->t == 3 || ((f->flg & 8) && (f->t == 7 || f->t == 8))) * 2;
	if (!adr && val == 0)
		pred = 0;
	if (!((hex = get_hex(f, val, capital)) && padd_non_str(f, pred)))
		return (0);
	if (!(f->flg & 128))
		f->size += write(f->fd, f->p, f->p_len);
	if (capital && pred)
		f->size += write(f->fd, "0X", pred);
	if (!capital && pred)
		f->size += write(f->fd, "0x", pred);
	f->size += write(f->fd, f->s, f->s_len);
	f->size += write(f->fd, hex + ft_strlen(hex) - f->dig, f->dig);
	if (f->flg & 128)
		f->size += write(f->fd, f->p, f->p_len);
	free_ptr((void *)(&hex));
	return (1);
}
