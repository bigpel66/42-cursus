/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:12:18 by jseo              #+#    #+#             */
/*   Updated: 2021/05/07 17:39:12 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ostream_title(const char *s, int idx)
{
	size_t	i;

	i = -1;
	while (++i < 70)
		printf("=");
	ostream_endl();
	if (idx)
		printf("\t\t\t\t%s %d\t\t\t\t\n", s, idx);
	else
		printf("\t\t\t\t%s\t\t\t\t\n", s);
	i = -1;
	while (++i < 70)
		printf("=");
	ostream_endl();
}

void	ostream_vector(const t_vec3 *v, const char *s)
{
	printf("%s%+15.6f\t%+15.6f\t%+15.6f\n", s, v->x, v->y, v->z);
}

void	ostream_color(const t_color *c, const char *s)
{
	printf("%s%15.6f\t%15.6f\t%15.6f\n", s, c->r, c->g, c->b);
}

void	ostream_floating_point(double d, const char *s)
{
	printf("%s%15.6f\n", s, d);
}

void	ostream_endl(void)
{
	printf("\n");
}
