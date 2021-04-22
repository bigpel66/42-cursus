/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 23:16:10 by jseo              #+#    #+#             */
/*   Updated: 2021/04/22 13:48:08 by jseo             ###   ########.fr       */
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
