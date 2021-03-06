/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:12:23 by jseo              #+#    #+#             */
/*   Updated: 2021/04/25 17:21:50 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	e_file_param(void)
{
	errno = 22;
	perror("Type: Input param\nerrno 22");
	write(STDERR_FILENO, "ERROR\n", 6);
	exit(INVALID);
}

void	e_file_option(void)
{
	errno = 22;
	perror("Type: Input option\nerrno 22");
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

void	e_file_open(t_mlx *m)
{
	errno = 9;
	perror("Type: File open\nerrno 9");
	write(STDERR_FILENO, "ERROR\n", 6);
	mlx_free(m);
	exit(INVALID);
}

void	e_file_read(void **ptr, t_mlx *m, int fd)
{
	errno = 45;
	perror("Type: File read\nerrno 45");
	write(STDERR_FILENO, "ERROR\n", 6);
	free_ptr(ptr);
	mlx_free(m);
	close(fd);
	exit(INVALID);
}
