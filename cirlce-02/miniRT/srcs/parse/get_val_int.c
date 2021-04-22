/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_val_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 23:15:48 by jseo              #+#    #+#             */
/*   Updated: 2021/04/22 17:08:14 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	uint(char **line, int *v)
{
	t_bool	sign;

	if (!line || !(*line))
		return (FALSE);
	while (is_blank(**line))
		++(*line);
	sign = 1;
	if (**line == '-')
	{
		sign = ~(sign) + 1;
		++(*line);
	}
	if (is_digit(**line))
		while (is_digit(**line))
			*v = *v * 10 + (*((*line)++) - '0');
	else
		return (FALSE);
	if (is_blank(**line) || !(**line) || **line == ',')
	{
		*v = *v * sign;
		return (TRUE);
	}
	return (FALSE);
}

t_bool	sint(char **line, int *v1, int *v2, int *v3)
{
	*v1 = 0;
	*v2 = 0;
	*v3 = 0;
	if (!uint(line, v1) && **line != ',')
		return (FALSE);
	if (**line != ',')
		return (FALSE);
	++(*line);
	if (!uint(line, v2) && **line != ',')
		return (FALSE);
	if (**line != ',')
		return (FALSE);
	++(*line);
	if (!uint(line, v3))
		return (FALSE);
	return (TRUE);
}
