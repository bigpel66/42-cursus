/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   series_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 23:15:48 by jseo              #+#    #+#             */
/*   Updated: 2021/04/21 16:45:50 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
