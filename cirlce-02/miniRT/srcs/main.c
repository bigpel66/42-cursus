/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:24:34 by jseo              #+#    #+#             */
/*   Updated: 2021/04/23 14:41:54 by jseo             ###   ########.fr       */
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

	// hit_record
	// hit function on every objects
	// material
	// print_error_list();
	if (argc < 2 || argc > 3)
		e_file_argument();
	if (argc == 3 && ft_strncmp(argv[2], "-save", 5))
		e_option();
	scene_open(&m, argv[1], CHECK);
	if (!scene_init(&(m.rt)) || !obj_init(&m))
		e_element_memory(&m);
	scene_open(&m, argv[1], PARSE);
	mlx_setup(&m, argv[1]);
	mlx_calc();
	if (argc == 2)
		mlx_run(&m);
	else
		mlx_save();
	mlx_free(&m);
	while (TRUE);
	return (VALID);
}
