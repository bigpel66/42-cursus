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
