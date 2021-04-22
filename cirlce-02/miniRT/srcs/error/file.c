/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_argument.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:12:23 by jseo              #+#    #+#             */
/*   Updated: 2021/04/18 23:14:15 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	e_file_argument(void)
{
	errno = 22;
	perror("Type: Input argc\nerrno 22");
	printf("Error\n");
	exit(INVALID);
}

void	e_file_extname(void)
{
	errno = 79;
	perror("Type: File extname\nerrno 79");
	printf("Error\n");
	exit(INVALID);
}

void	e_file_open(t_scene *rt)
{
	errno = 9;
	perror("Type: File open\nerrno 9");
	printf("Error\n");
	free_scene(rt);
	exit(INVALID);
}

void	e_file_read(void **ptr, t_scene *rt, int *fd)
{
	errno = 45;
	perror("Type: File read\nerrno 45");
	printf("Error\n");
	free_ptr(ptr);
	free_scene(rt);
	close(*fd);
	exit(INVALID);
}
