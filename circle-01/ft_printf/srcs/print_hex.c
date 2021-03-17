/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:42:00 by jseo              #+#    #+#             */
/*   Updated: 2021/03/17 12:42:03 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(t_form *f, unsigned long long val, int capital)
{
	int		pred;
	char	*hex;
	char	*pf;
	char	*sf;

	pred = (f->t == 3 || ((f->flg & 8) && (f->t == 7 || f->t == 8))) * 2;
	if (!((hex = get_hex(f, val, capital)) && padd_non_str(f, &pf, &sf, pred)))
		return (0);
	if (!(f->flg & 128))
		f->size += write(f->fd, pf, ft_strlen(pf));
	if (capital && pred)
		f->size += write(f->fd, "0X", 2);
	if (!capital && pred)
		f->size += write(f->fd, "0x", 2);
	f->size += write(f->fd, sf, ft_strlen(sf));
	f->size += write(f->fd, hex + ft_strlen(hex) - f->dig, f->dig);
	if (f->flg & 128)
		f->size += write(f->fd, pf, ft_strlen(pf));
	free_ptr((void *)(&hex));
	free_ptr((void *)(&pf));
	free_ptr((void *)(&sf));
	return (1);
}
