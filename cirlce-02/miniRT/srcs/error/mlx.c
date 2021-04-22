/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_mlx_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:55:25 by jseo              #+#    #+#             */
/*   Updated: 2021/04/21 14:44:37 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	e_mlx_run(t_scene *rt)
{
	errno = 85;
	perror("Type: Cannot run mlx\nerrno 85");
	printf("Error\n");
	free_scene(rt);
	exit(INVALID);
}

void	e_mlx_screen_connection(t_scene *rt)
{
	errno = 49;
	perror("Type: Creation of screen connection\nerrno 49");
	printf("\nError\n");
	free_scene(rt);
	exit(INVALID);
}

void	e_mlx_window(t_scene *rt)
{
	errno = 49;
	perror("Type: Creation of window\nerrno 49");
	printf("\nError\n");
	free_scene(rt);
	exit(INVALID);
}

void	e_mlx_image(t_scene *rt)
{
	errno = 49;
	perror("Type: Creation of image\nerrno 49");
	printf("\nError\n");
	free_scene(rt);
	exit(INVALID);
}
