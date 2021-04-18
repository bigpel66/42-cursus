/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:24:34 by jseo              #+#    #+#             */
/*   Updated: 2021/04/18 15:41:19 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			mlx_ready(t_mlx *m)
{
	m->sid = mlx_init();
	if (!(m->sid))
		e_screen_connection();
	m->wid = mlx_new_window(m->sid, 400, 300, "miniRT");
	if (!(m->wid))
		e_window();
}

static t_bool	scene_parse(t_mlx *m, char *line)
{
	printf("%s\n", line);
	m->img = NULL;
	return (TRUE);
}

static void		scene_open(t_mlx *m, const char *filename)
{
	char	*line;
	char	*extname;
	int		fd;
	int		ret;

	extname = ft_strchr(filename, '.');
	if (!extname || ft_strncmp(extname, ".rt", 3))
		e_file_extname();
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		e_file_open();
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret < 0)
			e_file_read();
		if (!scene_parse(m, line))
			e_file_parsing();
		free_ptr((void **)(&line));
		if (ret == 0)
			break ;
	}
}

int				main(int argc, char **argv)
{
	t_mlx	m;

	// print_error_list();
	if (argc != 2)
		e_argument();
	scene_open(&m, argv[1]);
	mlx_ready(&m);
	while (1); // debugging
	// mlx_loop(m.sid);
	return (VALID);
}
