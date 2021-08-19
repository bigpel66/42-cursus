/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:37:44 by jseo              #+#    #+#             */
/*   Updated: 2021/08/12 10:24:58 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_arg(t_op *op, t_philo **philo)
{
	int		i;

	i = -1;
	if (op->f)
		while (++i < op->total)
			pthread_mutex_destroy(&op->f[i]);
	jfree((void **)(&op->f));
	jfree((void **)(philo));
	pthread_mutex_destroy(&op->t);
	pthread_mutex_destroy(&op->p);
}

t_exit	exit_invalid(t_op *op, t_philo **philo, void (*f)(void))
{
	if (f)
		f();
	free_arg(op, philo);
	return (INVALID);
}

t_exit	exit_valid(t_op *op, t_philo **philo)
{
	free_arg(op, philo);
	return (VALID);
}
