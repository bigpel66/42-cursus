/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_with_dot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:22:34 by jseo              #+#    #+#             */
/*   Updated: 2021/03/17 12:22:42 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	allocate_with_dot(t_form *f, char **pf, char **sf, int padd)
{
	long long	val;
	long long	p_len;
	long long	s_len;

	val = f->dig;
	p_len = 0;
	s_len = 0;
	if (f->dig < f->prec)
	{
		val = f->prec;
		s_len = f->prec - f->dig;
	}
	if (val + padd < f->width)
		p_len = f->width - (val + padd);
	*pf = (char *)ft_calloc(p_len + 1, sizeof(char));
	*sf = (char *)ft_calloc(s_len + 1, sizeof(char));
	if (!(*pf && *sf))
		return (0);
	ft_memset(*pf, 32, p_len);
	ft_memset(*sf, 48, s_len);
	return (1);
}
