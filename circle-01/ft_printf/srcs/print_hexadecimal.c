#include "ft_printf.h"

int print_hexadecimal(t_form *f, unsigned long long val, int capital)
{
	int pred;
	char *adr;
	char *pref;
	char *suff;

	pred = (f->type == 3 || ((f->flag & 8) && (f->type == 7 || f->type == 8))) * 2;
	if (!((adr = get_hexadecimal(f, val, capital)) && padd_non_string(f, &pref, &suff, pred)))
		return (0);
	if (!(f->flag & 128))
		f->size += write(f->fd, pref, ft_strlen(pref));
	if (capital && pred)
		f->size += write(f->fd, "0X", 2);
	if (!capital && pred)
		f->size += write(f->fd, "0x", 2);
	f->size += write(f->fd, suff, ft_strlen(suff));
	f->size += write(f->fd, adr + ft_strlen(adr) - f->digit, f->digit);
	if (f->flag & 128)
		f->size += write(f->fd, pref, ft_strlen(pref));
	free_ptr((void *)(&adr));
	free_ptr((void *)(&pref));
	free_ptr((void *)(&suff));
	return (1);
}
