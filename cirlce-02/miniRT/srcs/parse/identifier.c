/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:13:26 by jseo              #+#    #+#             */
/*   Updated: 2021/04/25 15:19:00 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	get_identifier(char **s)
{
	int	i;

	i = get_index("RAcl", (*s)[0]);
	if (i > 0 && is_blank((*s)[1]))
		return (i);
	i = get_index("spct", (*s)[0]);
	if (i == 1 && (*s)[1] == 'p')
		return (SPHERE);
	if (i == 1 && (*s)[1] == 'q')
		return (SQUARE);
	if (i == 2 && (*s)[1] == 'l')
		return (PLANE);
	if (i == 3 && (*s)[1] == 'y')
		return (CYLINDER);
	if (i == 3 && (*s)[1] == 'o')
		return (CONE);
	if (i == 4 && (*s)[1] == 'r')
		return (TRIANGLE);
	return (0);
}
