/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:20:24 by jseo              #+#    #+#             */
/*   Updated: 2021/04/25 17:21:46 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	e_pthread_mutex(void **ptr, t_mlx *m)
{
	errno = 77;
	perror("Type: Pthread mutex creation\nerrno 77");
	write(STDERR_FILENO, "ERROR\n", 6);
	free_ptr(ptr);
	mlx_free(m);
	exit(INVALID);
}

void	e_pthread_param(void **ptr, pthread_mutex_t *l, t_mlx *m)
{
	errno = 12;
	perror("Type: Pthread argument creation\nerrno 12");
	write(STDERR_FILENO, "ERROR\n", 6);
	free_ptr(ptr);
	if (l)
		pthread_mutex_destroy(l);
	mlx_free(m);
	exit(INVALID);
}

void	e_pthread_create(void **ptr, pthread_mutex_t *l, t_mlx *m)
{
	errno = 10;
	perror("Type: Pthread creation\nerrno 10");
	write(STDERR_FILENO, "ERROR\n", 6);
	free_ptr(ptr);
	if (l)
		pthread_mutex_destroy(l);
	mlx_free(m);
	exit(INVALID);
}

void	e_pthread_join(void **ptr, pthread_mutex_t *l, t_mlx *m)
{
	errno = 3;
	perror("Type: Pthread join\nerrno 3");
	write(STDERR_FILENO, "ERROR\n", 6);
	free_ptr(ptr);
	if (l)
		pthread_mutex_destroy(l);
	mlx_free(m);
	exit(INVALID);
}
