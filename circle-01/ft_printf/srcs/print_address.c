#include "ft_printf.h"

int print_address(t_form *f, unsigned long long val)
{
	char *adr;
	char *pref;
	char *suff;

	if (!((adr = get_address(f, val)) && padd_non_string(f, &pref, &suff, 2)))
		return (0);
	if (!(f->flag & 128))
		f->size += write(f->fd, pref, ft_strlen(pref));
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
