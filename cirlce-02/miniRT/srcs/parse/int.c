/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 23:15:48 by jseo              #+#    #+#             */
/*   Updated: 2021/04/25 15:19:05 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	uint(char **s, int *v)
{
	t_bool	sign;

	if (!s || !(*s))
		return (FALSE);
	while (is_blank(**s))
		++(*s);
	sign = 1;
	if (**s == '-')
	{
		sign = ~(sign) + 1;
		++(*s);
	}
	if (is_digit(**s))
		while (is_digit(**s))
			*v = *v * 10 + (*((*s)++) - '0');
	else
		return (FALSE);
	if (is_blank(**s) || !(**s) || **s == ',')
	{
		*v = *v * sign;
		return (TRUE);
	}
	return (FALSE);
}

t_bool	sint(char **s, int *v1, int *v2, int *v3)
{
	*v1 = 0;
	*v2 = 0;
	*v3 = 0;
	if (!uint(s, v1) && **s != ',')
		return (FALSE);
	if (**s != ',')
		return (FALSE);
	++(*s);
	if (!uint(s, v2) && **s != ',')
		return (FALSE);
	if (**s != ',')
		return (FALSE);
	++(*s);
	if (!uint(s, v3))
		return (FALSE);
	return (TRUE);
}
