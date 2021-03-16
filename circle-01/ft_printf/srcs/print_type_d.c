#include "ft_printf.h"

int d_dot(t_form *f, char **pref, char **suff, long long len, int padd)
{
	long long val;
	long long p_len;
	long long s_len;

	val = len;
	p_len = 0;
	s_len = 0;
	if (len < f->precision)
	{
		val = f->precision;
		s_len = f->precision - len;
	}
	if (val + padd < f->width)
		p_len = f->width - (val + padd);
	*pref = (char *)ft_calloc(p_len + 1, sizeof(char));
	*suff = (char *)ft_calloc(s_len + 1, sizeof(char));
	if (!(*pref && *suff))
		return (0);
	ft_memset(*pref, 32, p_len);
	ft_memset(*suff, 48, s_len);
	return (1);
}

int dw_dot(t_form *f, char **pref, char **suff, long long len, int padd)
{
	char *tmp;
	long long p_len;
	long long s_len;

	tmp = NULL;
	p_len = 0;
	s_len = 0;
	if (len + padd < f->width)
		p_len = f->width - (len + padd);
	*suff = (char *)ft_calloc(s_len + 1, sizeof(char));
	*pref = (char *)ft_calloc(p_len + 1, sizeof(char));
	if (!(*pref && *suff))
		return (0);
	if (f->flag & ((char)1 << 4))
	{
		tmp = *pref;
		*pref = *suff;
		*suff = tmp;
	}
	ft_memset(*pref, 32, p_len);
	ft_memset(*suff, 48, s_len);
	return (1);
}
int padd_d(t_form *f, char **pref, char **suff, long long len, int minus)
{
	int ret;
	int padd;

	padd = 0;
	if (minus || (!minus && f->flag & 64) || (!minus && !(f->flag & 64) && f->flag & 32))
		padd = 1;
	if (f->flag & 4)
		ret = d_dot(f, pref, suff, len, padd);
	else
		ret = dw_dot(f, pref, suff, len, padd);
	if (!ret)
		return (0);
	return (1);
}

char *get_nbr(long long val, int base, long long *len)
{
	long long tmp;
	long long i;
	char *buf;

	tmp = val;
	*len = 0;
	while (tmp && ++(*len))
		tmp /= base;
	i = *len;
	if (val < 0)
		val = ~(val) + 1;
	if (!(buf = (char *)ft_calloc(i + 1, sizeof(char))))
		return (NULL);
	while (val)
	{
		buf[--i] = "0123456789abcdef"[val % base];
		val /= base;
	}
	return (buf);
}

int print_type_d(t_form *f, int arg)
{
	char *nbr;
	long long len;
	char *pref;
	char *suff;

	if (!((nbr = get_nbr(arg, 10, &len)) && padd_d(f, &pref, &suff, len, arg < 0)))
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
	f->size += write(f->fd, nbr, len);
	if (f->flag & 128)
		f->size += write(f->fd, pref, ft_strlen(pref));
	free_ptr((void *)(&nbr));
	free_ptr((void *)(&pref));
	free_ptr((void *)(&suff));
	return (1);
}
