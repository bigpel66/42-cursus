/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:27 by jseo              #+#    #+#             */
/*   Updated: 2021/04/23 18:41:07 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			to_string_c(t_camera *c, int idx)
{
	ostream_title("Camera", idx);
	ostream_vector(&(c->p), "Camera Position\t\t");
	ostream_vector(&(c->o), "Camera Orientation\t");
	ostream_floating_point(c->fov, "Camrea Field of View\t");
	printf("\n");
}

static t_bool	valid_c(t_camera *c)
{
	t_bool	ret;

	ret = TRUE;
	if (!valid_vec3(c->o))
		ret = FALSE;
	if (c->fov < 0.0 || c->fov > 180.0)
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Detail: Invalid camera value\n", 29);
	return (ret);
}

static t_bool	parse_c(t_camera *c, char *line, int idx)
{
	t_bool	ret;

	ret = TRUE;
	if (!sdouble(&line, &(c->p.x), &(c->p.y), &(c->p.z)))
		ret = FALSE;
	if (!sdouble(&line, &(c->o.x), &(c->o.y), &(c->o.z)))
		ret = FALSE;
	if (!udouble(&line, &(c->fov)))
		ret = FALSE;
	to_string_c(c, idx + 1);
	if (!is_endl(line))
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Detail: Wrong parsing camera\n", 29);
	return (ret);
}

t_bool			get_camera(t_scene *rt, char *line)
{
	static int	i;

	if (!parse_c(&((rt->c)[i]), line, i) || !valid_c(&((rt->c)[i])))
		return (FALSE);
	++i;
	return (TRUE);
}

t_bool			chk_camera(t_scene *rt)
{
	++(rt->cnt.c);
	return (TRUE);
}
