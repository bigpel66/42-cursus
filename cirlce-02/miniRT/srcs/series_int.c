/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sint.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 23:15:48 by jseo              #+#    #+#             */
/*   Updated: 2021/04/19 10:53:32 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool sint(char **line, int *v1, int *v2, int *v3)
{
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
