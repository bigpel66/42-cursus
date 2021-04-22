/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 23:16:06 by jseo              #+#    #+#             */
/*   Updated: 2021/04/22 13:48:12 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	udouble(char **line, double *v)
{
	int	i;

	i = 0;
	if (!line || !(*line))
		return (FALSE);
	if (!uint(line, &i) && **line != '.')
		return (FALSE);
	*v += (double)i;
	if (**line == '.')
	{
		if (!is_digit(*(++(*line))))
			return (FALSE);
		i = 0;
		while (TRUE)
		{
			if (is_blank(**line) || !(**line))
				break ;
			if (!is_digit(**line))
				return (FALSE);
			*v += (1.0 / pow(10.0, ++i)) * (double)(*((*line)++) - '0');
		}
	}
	return (TRUE);
}
