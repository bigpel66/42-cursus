/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   series_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 23:15:44 by jseo              #+#    #+#             */
/*   Updated: 2021/04/22 13:47:53 by jseo             ###   ########.fr       */
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

t_bool	sdouble(char **line, double *v1, double *v2, double *v3)
{
	*v1 = 0.0;
	*v2 = 0.0;
	*v3 = 0.0;
	if (!udouble(line, v1) && **line != ',')
		return (FALSE);
	if (**line != ',')
		return (FALSE);
	++(*line);
	if (!udouble(line, v2) && **line != ',')
		return (FALSE);
	if (**line != ',')
		return (FALSE);
	++(*line);
	if (!udouble(line, v3))
		return (FALSE);
	return (TRUE);
}
