/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 17:10:29 by jseo              #+#    #+#             */
/*   Updated: 2021/05/07 17:10:31 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	e_texture_alloc(void **ptr, t_mlx *m, int fd)
{
	errno = 12;
	perror("Type: Memory allocation\nerrno 12");
	write(STDERR_FILENO, "ERROR\n", 6);
	free_ptr(ptr);
	mlx_free(m);
	close(fd);
	exit(INVALID);
}

void	e_texture_read(void **p1, void **p2, t_mlx *m, int fd)
{
	errno = 45;
	perror("Type: File read\nerrno 45");
	write(STDERR_FILENO, "ERROR\n", 6);
	free_ptr(p1);
	free_ptr(p2);
	mlx_free(m);
	close(fd);
	exit(INVALID);
}

void	e_texture_format(void **ptr, t_mlx *m, int fd)
{
	errno = 79;
	perror("Type: File format\nerrno 79");
	write(STDERR_FILENO, "ERROR\n", 6);
	free_ptr(ptr);
	mlx_free(m);
	close(fd);
	exit(INVALID);
}
