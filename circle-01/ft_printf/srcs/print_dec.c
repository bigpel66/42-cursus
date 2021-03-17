/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:41:43 by jseo              #+#    #+#             */
/*   Updated: 2021/03/17 12:41:45 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_dec(t_form *f, long long arg, int sign)
{
	int		pred;
	char	*nbr;
	char	*pf;
	char	*sf;

	pred = sign && (arg < 0 || (arg >= 0 && f->flg & 64) ||
			(arg >= 0 && !(f->flg & 64) && f->flg & 32));
	if (!((nbr = get_dec(f, arg)) && padd_non_str(f, &pf, &sf, pred)))
		return (0);
	if (sign && arg >= 0 && !(f->flg & 64) && f->flg & 32)
		f->size += write(f->fd, " ", 1);
	if (!(f->flg & 128))
		f->size += write(f->fd, pf, ft_strlen(pf));
	if (sign && arg < 0)
		f->size += write(f->fd, "-", 1);
	else if (sign && f->flg & 64)
		f->size += write(f->fd, "+", 1);
	f->size += write(f->fd, sf, ft_strlen(sf));
	f->size += write(f->fd, nbr, f->dig);
	if (f->flg & 128)
		f->size += write(f->fd, pf, ft_strlen(pf));
	free_ptr((void *)(&nbr));
	free_ptr((void *)(&pf));
	free_ptr((void *)(&sf));
	return (1);
}
