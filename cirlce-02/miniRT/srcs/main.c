/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:24:34 by jseo              #+#    #+#             */
/*   Updated: 2021/04/22 13:47:44 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		print_error_list(void)
{
	size_t	i;

	i = -1;
	while (++i < 107)
		printf("%zu: %s\n", i, strerror(i));
}

int				main(int argc, char **argv)
{
	t_mlx	m;
	t_scene	rt;

	// print_error_list();
	if (argc != 2)
		e_file_argument();
	scene_operation(&rt, argv[1], CHECK);
	if (!scene_init(&rt))
		e_element_memory(&rt);
	scene_operation(&rt, argv[1], PARSE);
	if (rt.r.w && rt.r.h)
	{
		mlx_ready(&m, &rt, argv[1]);
		mlx_loop(m.sid);
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
