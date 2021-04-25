/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:08:34 by jseo              #+#    #+#             */
/*   Updated: 2021/04/25 17:21:39 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	arg_init(void **arg, t_mux *l, t_mlx *m, int i)
{
	if (!dalloc(arg, 1, sizeof(t_arg)))
		return (FALSE);
	(*(t_arg **)arg)->lock = l;
	(*(t_arg **)arg)->m = m;
	(*(t_arg **)arg)->i = i;
	return (TRUE);
}

void	*mlx_img_calc(void *arg)
{
	printf("\nImage calculating at index %d\n", ((t_arg *)arg)->i + 1);
	free_ptr(&arg);
	return (NULL);
}

void	mlx_calc(t_mlx *m)
{
	int			i;
	pthread_t	*images;
	t_arg		*arg;

	i = -1;
	if (!dalloc((void **)(&images), m->rt.cnt.c, sizeof(pthread_t)))
		e_memory_alloc(m);
	while (++i < m->rt.cnt.c)
	{
		if (!arg_init((void **)(&arg), NULL, m, i))
			e_thread_param((void **)(&images), NULL, m);
		if (pthread_create(&images[i], NULL, mlx_img_calc, arg))
			e_thread_open((void **)(&images), (void **)(&arg), NULL, m);
	}
	while (i--)
		if (pthread_join(images[i], NULL))
			e_thread_join((void **)(&images), NULL, m);
	i = m->rt.cnt.c;
	while (i--)
		wait(NULL);
	free_ptr((void **)(&images));
}
