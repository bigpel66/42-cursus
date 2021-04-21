/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:24:34 by jseo              #+#    #+#             */
/*   Updated: 2021/04/21 14:44:53 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	get_info(t_scene *rt, char *line, t_bool id)
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

static t_bool	scene_parse(t_scene *rt, char *line)
{
	t_bool	id;

	id = FALSE;
	if (!ft_strncmp(line, "", ft_strlen(line)))
		return (TRUE);
	while (is_blank(*line))
		++line;
	id = is_identifier(&line);
	if (!id)
	{
		printf("Detail: Occured on type parsing\n");
		return (FALSE);
	}
	else if (id <= 4)
		line = line + 2;
	else
		line = line + 3;
	if (!get_info(rt, line, id))
		return (FALSE);
	return (TRUE);
}

static void		scene_open(t_scene *rt, const char *filename)
{
	char	*line;
	char	*extname;
	int		fd;
	int		ret;

	ft_memset((void *)rt, 0, sizeof(t_scene));
	extname = ft_strchr(filename, '.');
	if (!extname || ft_strncmp(extname, ".rt", 3))
		e_file_extname();
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		e_file_open();
	while (TRUE)
	{
		ret = ft_gnl(fd, &line);
		if (ret < 0)
			e_file_read();
		if (!scene_parse(rt, line))
			e_file_parsing((void **)(&line));
		free_ptr((void **)(&line));
		if (ret == 0)
			break ;
	}
}

int				main(int argc, char **argv)
{
	t_mlx	m;
	t_scene	rt;

	// print_error_list();
	if (argc != 2)
		e_argument();
	scene_open(&rt, argv[1]);
	if (rt.r.w && rt.r.h)
	{
		mlx_ready(&m, &rt, argv[1]);
		mlx_loop(m.sid);
	}
	else
		e_mlx_run();
	// while (TRUE)
	// 	;
	return (VALID);
	// TODO 1: It's not implemented watching the pos of obj by resolution -> By making validate_pos_to_res function
	// TODO 2: hit formula for the every objects, make the pixels on the screen
}
