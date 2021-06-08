/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_string2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 17:30:07 by jseo              #+#    #+#             */
/*   Updated: 2021/05/07 17:30:09 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	to_string_sp(t_sphere *sp, int idx)
{
	ostream_title("Sphere", idx);
	ostream_vector(&(sp->p), "Sphere Position\t\t");
	ostream_floating_point(sp->d, "Sphere Diameter\t\t");
	ostream_color(&(sp->c), "Sphere Color\t\t");
	ostream_floating_point(sp->r, "Sphere Radius\t\t");
	if (sp->f)
		printf("Sphere Texture Image\t\t%s\n", sp->f);
	ostream_endl();
}

void	to_string_pl(t_plane *pl, int idx)
{
	ostream_title("Plane", idx);
	ostream_vector(&(pl->p), "Plane Position\t\t");
	ostream_vector(&(pl->n), "Plane Normal\t\t");
	ostream_color(&(pl->c), "Plane Color\t\t");
	ostream_endl();
}

void	to_string_sq(t_square *sq, int idx)
{
	ostream_title("Square", idx);
	ostream_vector(&(sq->p), "Square Position\t\t");
	ostream_vector(&(sq->n), "Square Normal\t\t");
	ostream_floating_point(sq->l, "Square Side Length\t");
	ostream_color(&(sq->c), "Square Color\t\t");
	ostream_endl();
}

void	to_string_cy(t_cylinder *cy, int idx)
{
	ostream_title("Cylinder", idx);
	ostream_vector(&(cy->p), "Cylinder Position\t");
	ostream_vector(&(cy->o), "Cylinder Orientation\t");
	ostream_floating_point(cy->d, "Cylinder Diameter\t");
	ostream_floating_point(cy->h, "Cylinder Height\t\t");
	ostream_color(&(cy->c), "Cylinder Color\t");
	ostream_floating_point(cy->r, "Cylinder Radius\t\t");
	ostream_vector(&(cy->tc), "Cylinder Top Center\t");
	ostream_vector(&(cy->bc), "Cylinder Bottom Center\t");
	ostream_endl();
}

void	to_string_tr(t_triangle *tr, int idx)
{
	ostream_title("Triangle", idx);
	ostream_vector(&(tr->p1), "Triangle Position 1\t");
	ostream_vector(&(tr->p2), "Triangle Position 2\t");
	ostream_vector(&(tr->p3), "Triangle Position 3\t");
	ostream_color(&(tr->c), "Triangle Color\t");
	ostream_vector(&(tr->n), "Triangle Normal\t\t");
	ostream_endl();
}
