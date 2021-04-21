/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:24:34 by jseo              #+#    #+#             */
/*   Updated: 2021/04/21 20:01:11 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_mlx	m;
	t_scene	rt;

	print_error_list();
	if (argc != 2)
		e_argument();
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
		e_mlx_run();
	// while (TRUE)
	// 	;
	free_scene(&rt);
	return (VALID);
	// TODO 1: It's not implemented watching the pos of obj by resolution -> By making validate_pos_to_res function
	// TODO 2: hit formula for the every objects, make the pixels on the screen
}
