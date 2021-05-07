/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_string1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 17:30:04 by jseo              #+#    #+#             */
/*   Updated: 2021/05/07 18:17:09 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	to_string_r(t_scene *rt, int idx)
{
	ostream_title("Resolution", idx);
	printf("%s%d\n", "Resolution Width\t\t", rt->r.w);
	printf("%s%d\n", "Resolution Height\t\t", rt->r.h);
	ostream_floating_point(rt->r.ar, "Resolution Aspect Ratio\t");
	printf("\n");
}

void	to_string_a(t_scene *rt, int idx)
{
	ostream_title("Ambient", idx);
	ostream_floating_point(rt->a.s, "Ambient Ratio\t\t");
	ostream_color(&(rt->a.c), "Ambient Color\t\t");
	printf("\n");
}

void	to_string_c(t_camera *c, int idx)
{
	ostream_title("Camera", idx);
	ostream_vector(&(c->p), "Camera Position\t\t");
	ostream_vector(&(c->o), "Camera Orientation\t");
	ostream_floating_point(c->fov, "Camrea Field of View\t");
	printf("\n");
}

void	to_string_l(t_light *l, int idx)
{
	ostream_title("Light", idx);
	ostream_vector(&(l->p), "Light Position\t\t");
	ostream_floating_point(l->s, "Light Ratio\t\t");
	ostream_color(&(l->c), "Light Color\t\t");
	printf("\n");
}

void	to_string_co(t_cone *co, int idx)
{
	ostream_title("Cone", idx);
	ostream_vector(&(co->p), "Cone Position\t\t");
	ostream_vector(&(co->o), "Cone Orientation\t");
	ostream_floating_point(co->a, "Cone Angle (Degree)\t");
	ostream_floating_point(co->h, "Cone Height\t\t");
	ostream_color(&(co->c), "Cone Color\t\t");
	ostream_floating_point(co->a, "Cone Angle (Radian)\t");
	ostream_floating_point(co->r, "Cone Raidus\t\t");
	ostream_floating_point(co->cos2, "Cone Cos2 of Angle\t");
	ostream_floating_point(co->sin2, "Cone Sin2 of Angle\t");
	ostream_vector(&(co->tp), "Cone Apex Position\t");
	ostream_vector(&(co->to), "Cone Apex Orientation\t");
	printf("\n");
}
