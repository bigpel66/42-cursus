/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_without_dot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:22:59 by jseo              #+#    #+#             */
/*   Updated: 2021/03/17 12:23:04 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	allocate_without_dot(t_form *f, char **pf, char **sf, int padd)
{
	char		*tmp;
	long long	p_len;
	long long	s_len;

	tmp = NULL;
	p_len = 0;
	s_len = 0;
	if (f->dig + padd < f->width)
		p_len = f->width - (f->dig + padd);
	*sf = (char *)ft_calloc(s_len + 1, sizeof(char));
	*pf = (char *)ft_calloc(p_len + 1, sizeof(char));
	if (!(*pf && *sf))
		return (0);
	if (f->flg & ((char)1 << 4))
	{
		tmp = *pf;
		*pf = *sf;
		*sf = tmp;
	}
	ft_memset(*pf, 32, p_len);
	ft_memset(*sf, 48, s_len);
	return (1);
}
