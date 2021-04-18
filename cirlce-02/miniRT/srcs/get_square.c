/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:51 by jseo              #+#    #+#             */
/*   Updated: 2021/04/18 23:15:27 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	valid_square(t_mlx *m)
{
	if (!valid_vec3(m->i.sq.d))
	{
		printf("Detail: Occured on square direction\n");
		return (FALSE);
	}
	if (m->i.sq.l <= 0.0)
	{
		printf("Detail: Occured on square side length\n");
		return (FALSE);
	}
	if (!valid_color(m->i.sq.c))
	{
		printf("Detail: Occured on square color\n");
		return (FALSE);
	}
	return (TRUE);
}

t_bool			get_square(t_mlx *m, char *line)
{
	if (m->i.sq.f)
		return (FALSE);
	m->i.sq.f = TRUE;
	printf("%s\n", line);
	printf("size of tmlx %lu\n", sizeof(t_mlx));
	return (TRUE);
}
