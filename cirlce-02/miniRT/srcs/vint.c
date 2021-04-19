/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vint.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 23:16:10 by jseo              #+#    #+#             */
/*   Updated: 2021/04/19 13:51:35 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	vint(char **line, int *v)
{
	if (!line || !(*line))
		return (FALSE);
	while (is_blank(**line))
		++(*line);
	if (is_digit(**line))
	{
		while (1)
		{
			if (is_blank(**line) || !(**line))
				return (TRUE);
			if (!is_digit(**line))
				return (FALSE);
			*v = *v * 10 + (*((*line)++) - '0');
		}
	}
	return (FALSE);
}
