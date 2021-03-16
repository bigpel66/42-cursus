#include "ft_printf.h"

int print_signed_decimal(t_form *f, int arg)
{
	int pred;
	char *nbr;
	char *pref;
	char *suff;

	pred = (arg < 0 || (arg >= 0 && f->flag & 64) ||
			(arg >= 0 && !(f->flag & 64) && f->flag & 32));
	if (!((nbr = get_number(f, arg, 10)) && padd_non_string(f, &pref, &suff, pred)))
		return (0);
	if (arg >= 0 && !(f->flag & 64) && f->flag & 32)
		f->size += write(f->fd, " ", 1);
	if (!(f->flag & 128))
		f->size += write(f->fd, pref, ft_strlen(pref));
	if (arg < 0)
		f->size += write(f->fd, "-", 1);
	else if (f->flag & 64)
		f->size += write(f->fd, "+", 1);
	f->size += write(f->fd, suff, ft_strlen(suff));
	f->size += write(f->fd, nbr, f->digit);
	if (f->flag & 128)
		f->size += write(f->fd, pref, ft_strlen(pref));
	free_ptr((void *)(&nbr));
	free_ptr((void *)(&pref));
	free_ptr((void *)(&suff));
	return (1);
}
