/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ostream.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:12:18 by jseo              #+#    #+#             */
/*   Updated: 2021/04/23 14:41:38 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ostream_title(const char *s, int idx)
{
	size_t	i;

	i = -1;
	while (++i < 70)
		printf("=");
	printf("\n");
	if (idx)
		printf("\t\t\t\t%s %d\t\t\t\t\n", s, idx);
	else
		printf("\t\t\t\t%s\t\t\t\t\n", s);
	i = -1;
	while (++i < 70)
		printf("=");
	printf("\n");
}

void	ostream_vector(const t_vec3 *v, const char *s)
{
	printf("%s%12.6f\t%12.6f\t%12.6f\n", s, v->x, v->y, v->z);
}

void	ostream_color(const t_color *c, const char *s)
{
	printf("%s%12.6f\t%12.6f\t%12.6f\n", s, c->r, c->g, c->b);
}

void	ostream_floating_point(double d, const char *s)
{
	printf("%s%12.6f\n", s, d);
}