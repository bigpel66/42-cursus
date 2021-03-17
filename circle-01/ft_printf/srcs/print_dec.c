#include "ft_printf.h"

int print_dec(t_form *f, long long arg, int sig)
{
	char *dec;
	char *p;
	char *s;
	int pred;

	pred = sig && (arg < 0 || (arg >= 0 && (f->flg & 64 || f->flg & 32)));
	if (!((dec = get_dec(f, arg)) && padd_non_str(f, &p, &s, pred)))
		return (0);
	if (sig && arg >= 0 && !(f->flg & 64) && f->flg & 32)
		f->size += write(f->fd, " ", 1);
	if (sig && arg < 0 && p[0] == '0')
		f->size += write(f->fd, "-", 1);
	if (!(f->flg & 128))
		f->size += write(f->fd, p, ft_strlen(p));
	if (sig && arg < 0 && p[0] != '0')
		f->size += write(f->fd, "-", 1);
	else if (sig && f->flg & 64)
		f->size += write(f->fd, "+", 1);
	f->size += write(f->fd, s, ft_strlen(s));
	f->size += write(f->fd, dec, f->dig);
	if (f->flg & 128)
		f->size += write(f->fd, p, ft_strlen(p));
	// free_multi_ptr((void *)(&dec), (void *)(&p), (void *)(&s));
	return (1);
}
