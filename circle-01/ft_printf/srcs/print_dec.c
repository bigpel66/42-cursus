#include "ft_printf.h"

int print_dec(t_form *f, long long arg, int sig)
{
	int pred;
	char *dec;

	pred = sig && (arg < 0 || (arg >= 0 && (f->flg & 64 || f->flg & 32)));
	if (!((dec = get_dec(f, arg)) && padd_non_str(f, pred)))
		return (0);
	if (sig && arg >= 0 && !(f->flg & 64) && f->flg & 32)
		f->size += write(f->fd, " ", 1);
	if (sig && arg < 0 && (f->p)[0] == '0')
		f->size += write(f->fd, "-", 1);
	if (!(f->flg & 128))
		f->size += write(f->fd, f->p, f->p_len);
	if (sig && arg < 0 && (f->p)[0] != '0')
		f->size += write(f->fd, "-", 1);
	else if (sig && f->flg & 64)
		f->size += write(f->fd, "+", 1);
	f->size += write(f->fd, f->s, f->s_len);
	f->size += write(f->fd, dec, f->dig);
	if (f->flg & 128)
		f->size += write(f->fd, f->p, f->p_len);
	free_ptr((void *)(&dec));
	return (1);
}
