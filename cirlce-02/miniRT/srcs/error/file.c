/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:12:23 by jseo              #+#    #+#             */
/*   Updated: 2021/04/22 17:28:17 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	e_file_argument(void)
{
	errno = 22;
	perror("Type: Input argc\nerrno 22");
	write(STDERR_FILENO, "ERROR\n", 6);
	exit(INVALID);
}

void	e_file_extname(void)
{
	errno = 79;
	perror("Type: File extname\nerrno 79");
	write(STDERR_FILENO, "ERROR\n", 6);
	exit(INVALID);
}

void	e_file_open(t_scene *rt)
{
	errno = 9;
	perror("Type: File open\nerrno 9");
	write(STDERR_FILENO, "ERROR\n", 6);
	free_scene(rt);
	exit(INVALID);
}

void	e_file_read(void **ptr, t_scene *rt, int fd)
{
	errno = 45;
	perror("Type: File read\nerrno 45");
	write(STDERR_FILENO, "ERROR\n", 6);
	free_ptr(ptr);
	free_scene(rt);
	close(fd);
	exit(INVALID);
}
