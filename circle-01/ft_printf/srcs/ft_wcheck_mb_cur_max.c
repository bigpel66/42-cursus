/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcheck_mb_cur_max.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:08:32 by jseo              #+#    #+#             */
/*   Updated: 2021/03/21 14:08:36 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	ft_wcheck_mb_cur_max(wchar_t *s)
{
	t_bool	ret;

	ret = TR;
	while (*s)
	{
		if (*s >= 0 && *s <= 127)
			;
		else if (*s >= 0 && *s <= 255 && MB_CUR_MAX == 1)
			;
		else if (*s >= 128 && *s <= 2047 && MB_CUR_MAX >= 2)
			;
		else if (*s >= 2048 && *s <= 65535 && MB_CUR_MAX >= 3)
			;
		else if (*s >= 65536 && *s <= 2097151 && MB_CUR_MAX == 4)
			;
		else
		{
			ret = FL;
			break ;
		}
		++s;
	}
	return (ret);
}
