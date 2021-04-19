/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdouble.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 23:15:44 by jseo              #+#    #+#             */
/*   Updated: 2021/04/19 10:52:06 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool sdouble(char **line, double *v1, double *v2, double *v3)
{
	if (!vdouble(line, v1) && **line != ',')
		return (FALSE);
	if (**line != ',')
		return (FALSE);
	++(*line);
	if (!vdouble(line, v2) && **line != ',')
		return (FALSE);
	if (**line != ',')
		return (FALSE);
	++(*line);
	if (!vdouble(line, v3))
		return (FALSE);
	return (TRUE);
}
