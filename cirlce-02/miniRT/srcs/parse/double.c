/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 23:15:44 by jseo              #+#    #+#             */
/*   Updated: 2021/04/25 15:18:56 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	udouble(char **s, double *v)
{
	int	i;

	i = 0;
	if (!s || !(*s))
		return (FALSE);
	if (!uint(s, &i) && **s != '.')
		return (FALSE);
	*v += (double)i;
	if (**s == '.')
	{
		if (!is_digit(*(++(*s))))
			return (FALSE);
		i = 0;
		while (TRUE)
		{
			if (is_blank(**s) || !(**s))
				break ;
			if (!is_digit(**s))
				return (FALSE);
			*v += (1.0 / pow(10.0, ++i)) * (double)(*((*s)++) - '0');
		}
	}
	return (TRUE);
}

t_bool	sdouble(char **s, double *v1, double *v2, double *v3)
{
	*v1 = 0.0;
	*v2 = 0.0;
	*v3 = 0.0;
	if (!udouble(s, v1) && **s != ',')
		return (FALSE);
	if (**s != ',')
		return (FALSE);
	++(*s);
	if (!udouble(s, v2) && **s != ',')
		return (FALSE);
	if (**s != ',')
		return (FALSE);
	++(*s);
	if (!udouble(s, v3))
		return (FALSE);
	return (TRUE);
}
