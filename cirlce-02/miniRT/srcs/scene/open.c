/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:09:37 by jseo              #+#    #+#             */
/*   Updated: 2021/04/25 01:07:11 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	else if (id == CONE)
		ret = get_cone(rt, line);
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
	else if (id == CONE)
		ret = chk_cone(rt);
	return (ret);
}

static void		scene_process(t_mlx *m, char *line, int fd, t_bool chk)
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
		e_element_identifier((void **)(&line), m, fd);
	else if (id <= 4)
		tmp = tmp + 2;
	else
		tmp = tmp + 3;
	if (chk)
		if (!chk_element(&(m->rt), id))
			e_element_dup((void **)(&line), fd);
	if (!chk)
		if (!get_element(&(m->rt), tmp, id))
			e_element_parse((void **)(&line), m, fd);
}

void			scene_open(t_mlx *m, char *f, t_bool chk)
{
	char	*line;
	int		fd;
	int		ret;

	line = NULL;
	if (chk)
	{
		ft_memset((void *)m, 0, sizeof(t_mlx));
		if (!ft_strchr(f, '.') || ft_strncmp(ft_strchr(f, '.'), ".rt", 3))
			e_file_extname();
	}
	fd = open(f, O_RDONLY);
	if (fd < 0)
		e_file_open(m);
	while (TRUE)
	{
		ret = ft_gnl(fd, &line);
		if (ret < 0)
			e_file_read((void **)(&line), m, fd);
		scene_process(m, line, fd, chk);
		free_ptr((void **)(&line));
		if (!ret)
			break ;
	}
	close(fd);
}
