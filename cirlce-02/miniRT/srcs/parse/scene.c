/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:09:37 by jseo              #+#    #+#             */
/*   Updated: 2021/04/21 20:01:21 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool			scene_init(t_scene *rt)
{
	t_bool	ret;

	print_scene_count(rt);
	ret = TRUE;
	if (!dalloc((void **)(&(rt->c)), rt->cnt.c, sizeof(t_camera)))
		ret = FALSE;
	if (!dalloc((void **)(&(rt->l)), rt->cnt.l, sizeof(t_light)))
		ret = FALSE;
	if (!dalloc((void **)(&(rt->sp)), rt->cnt.sp, sizeof(t_sphere)))
		ret = FALSE;
	if (!dalloc((void **)(&(rt->pl)), rt->cnt.pl, sizeof(t_plane)))
		ret = FALSE;
	if (!dalloc((void **)(&(rt->sq)), rt->cnt.sq, sizeof(t_square)))
		ret = FALSE;
	if (!dalloc((void **)(&(rt->cy)), rt->cnt.cy, sizeof(t_cylinder)))
		ret = FALSE;
	if (!dalloc((void **)(&(rt->tr)), rt->cnt.tr, sizeof(t_triangle)))
		ret = FALSE;
	return (ret);
}

static t_bool	get_element(t_scene *rt, char *line, int id)
{
	t_bool	ret;

	ret = FALSE;
	if (id == RESOLUTION)
		ret = get_resolution(rt, line);
	else if (id == AMBIENT)
		ret = get_ambient(rt, line);
	else if (id == CAMERA)
		ret = get_camera(rt, line);
	else if (id == LIGHT)
		ret = get_light(rt, line);
	else if (id == SPHERE)
		ret = get_sphere(rt, line);
	else if (id == PLANE)
		ret = get_plane(rt, line);
	else if (id == SQUARE)
		ret = get_square(rt, line);
	else if (id == CYLINDER)
		ret = get_cylinder(rt, line);
	else if (id == TRIANGLE)
		ret = get_triangle(rt, line);
	return (ret);
}

static t_bool	chk_element(t_scene *rt, int id)
{
	t_bool	ret;

	ret = FALSE;
	if (id == RESOLUTION)
		ret = chk_resolution(rt);
	else if (id == AMBIENT)
		ret = chk_ambient(rt);
	else if (id == CAMERA)
		ret = chk_camera(rt);
	else if (id == LIGHT)
		ret = chk_light(rt);
	else if (id == SPHERE)
		ret = chk_sphere(rt);
	else if (id == PLANE)
		ret = chk_plane(rt);
	else if (id == SQUARE)
		ret = chk_square(rt);
	else if (id == CYLINDER)
		ret = chk_cylinder(rt);
	else if (id == TRIANGLE)
		ret = chk_triangle(rt);
	return (ret);
}

static void		scene_process(t_scene *rt, char *line, int *fd, t_bool chk)
{
	char	*tmp;
	int		id;

	tmp = line;
	id = NOTHING;
	if (!ft_strncmp(tmp, "", ft_strlen(tmp)))
		return ;
	while (is_blank(*tmp))
		++tmp;
	id = get_identifier(&tmp);
	if (!id)
		e_element_identifier((void **)(&line), rt, fd);
	else if (id <= 4)
		tmp = tmp + 2;
	else
		tmp = tmp + 3;
	if (chk)
		if (!chk_element(rt, id))
			e_element_dup((void **)(&line), fd);
	if (!chk)
		if (!get_element(rt, tmp, id))
			e_element_parse((void **)(&line), rt, fd);
}

void			scene_open(t_scene *rt, char *f, int *fd, t_bool chk)
{
	char	*line;
	int		ret;

	line = NULL;
	if (chk)
	{
		ft_memset((void *)rt, 0, sizeof(t_scene));
		if (!ft_strchr(f, '.') || ft_strncmp(ft_strchr(f, '.'), ".rt", 3))
			e_file_extname();
	}
	*fd = open(f, O_RDONLY);
	if (*fd < 0)
		e_file_open(rt);
	while (TRUE)
	{
		ret = ft_gnl(*fd, &line);
		if (ret < 0)
			e_file_read((void **)(&line), rt, fd);
		scene_process(rt, line, fd, chk);
		free_ptr((void **)(&line));
		if (ret == 0)
			break ;
	}
}
