/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:24:34 by jseo              #+#    #+#             */
/*   Updated: 2021/04/22 17:06:06 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_error_list(void)
{
	size_t	i;

	i = -1;
	while (++i < 107)
		printf("%zu: %s\n", i, strerror(i));
}

int		main(int argc, char **argv)
{
	t_mlx	m;
	t_scene	rt;
	int		fd;

	// print_error_list();
	if (argc < 2 || argc > 3)
		e_file_argument();
	scene_open(&rt, argv[1], &fd, CHECK);
	close(fd);
	if (!scene_init(&rt))
		e_element_memory(&rt);
	scene_open(&rt, argv[1], &fd, PARSE);
	close(fd);
	if (rt.r.w && rt.r.h)
	{
		mlx_setup(&m, &rt, argv[1]);
		mlx_calc();
		if (argc == 2)
			mlx_run();
		else if (argc == 3 && !(ft_strncmp(argv[2], "-save", 5)))
			mlx_save();
		else
			e_option(&rt);
	}
	else
		e_mlx_run(&rt);
	free_scene(&rt);
	while (TRUE)
		;
	return (VALID);
	// hit_record
	// hit_list
	// hit function on every objects
	// material
}
