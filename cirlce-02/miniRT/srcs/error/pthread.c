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

void	e_thread_open(void **t, void **p, t_mlx *m)
{
	errno = 10;
	perror("Type: Pthread creation\nerrno 10");
	write(STDERR_FILENO, "ERROR\n", 6);
	free_thread(t, p, NULL);
	mlx_free(m);
	exit(INVALID);
}

void	e_thread_join(void **t, void **p, t_mlx *m)
{
	errno = 3;
	perror("Type: Pthread join\nerrno 3");
	write(STDERR_FILENO, "ERROR\n", 6);
	free_thread(t, p, NULL);
	mlx_free(m);
	exit(INVALID);
}

void	e_thread_alloc(void **t, void **p, t_mlx *m)
{
	errno = 12;
	perror("Type: Pthread allocation\nerrno 12");
	write(STDERR_FILENO, "ERROR\n", 6);
	free_thread(t, p, NULL);
	mlx_free(m);
	exit(INVALID);
}

void	e_thread_exec(t_p *p, void **t, void **x, t_mux *l)
{
	errno = 0;
	perror("Type: Pthread execution\nerrno 0");
	write(STDERR_FILENO, "ERROR\n", 6);
	free_thread(t, x, l);
	free_thread((void **)(&(p->t)), (void **)(&(p->p)), NULL);
	mlx_free(p->m);
	exit(INVALID);
}
