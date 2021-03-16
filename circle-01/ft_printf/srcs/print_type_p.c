#include "ft_printf.h"

int allocate_with_dot(t_form *f, char **pref, char **suff, long long len)
{
	long long val;
	long long p_len;
	long long s_len;

	val = len + 2;
	p_len = 0;
	s_len = 0;
	if (len < f->precision)
	{
		val = f->precision + 2;
		s_len = f->precision - len;
	}
	if (val < f->width)
		p_len = f->width - val;
	*pref = (char *)ft_calloc(p_len + 1, sizeof(char));
	*suff = (char *)ft_calloc(s_len + 1, sizeof(char));
	if (!(*pref && *suff))
		return (0);
	ft_memset(*pref, 32, p_len);
	ft_memset(*suff, 48, s_len);
	return (1);
}

int allocate_without_dot(t_form *f, char **pref, char **suff, long long len)
{
	char *tmp;
	long long p_len;
	long long s_len;

	tmp = NULL;
	p_len = 0;
	s_len = 0;
	if (len + 2 < f->width)
		p_len = f->width - (len + 2);
	*pref = (char *)ft_calloc(p_len + 1, sizeof(char));
	*suff = (char *)ft_calloc(s_len + 1, sizeof(char));
	if (!(*pref && *suff))
		return (0);
	if (f->flag & 16)
	{
		tmp = *pref;
		*pref = *suff;
		*suff = tmp;
	}
	ft_memset(*pref, 32, p_len);
	ft_memset(*suff, 48, s_len);
	return (1);
}

int padd_p(t_form *f, char **pref, char **suff, long long len)
{
	int ret;

	if (f->flag & 4)
		ret = allocate_with_dot(f, pref, suff, len);
	else
		ret = allocate_without_dot(f, pref, suff, len);
	if (!ret)
		return (0);
	return (1);
}

char *get_address(unsigned long long val, long long *len)
{
	int shift;
	int offset;
	int i;
	char *buf;

	*len = 0;
	shift = sizeof(void *) * 2;
	offset = shift++;
	if (!(buf = (char *)ft_calloc(shift, sizeof(char))))
		return (NULL);
	while (--shift)
	{
		i = (val & (unsigned long long)15 << ((shift - 1) * 4)) >> ((shift - 1) * 4);
		buf[offset - shift] = "0123456789abcdef"[i];
		if (!*len && i)
			*len = shift;
	}
	return (buf);
}

int print_type_p(t_form *f, unsigned long long val)
{
	char *adr;
	long long len;
	char *pref;
	char *suff;

	if (!((adr = get_address(val, &len)) && padd_p(f, &pref, &suff, len)))
		return (0);
	if (!(f->flag & 128))
		f->size += write(f->fd, pref, ft_strlen(pref));
	f->size += write(f->fd, "0x", 2);
	f->size += write(f->fd, suff, ft_strlen(suff));
	f->size += write(f->fd, adr + ft_strlen(adr) - len, len);
	if (f->flag & 128)
		f->size += write(f->fd, pref, ft_strlen(pref));
	free_ptr((void *)(&adr));
	free_ptr((void *)(&pref));
	free_ptr((void *)(&suff));
	return (1);
}
