/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:52:18 by jseo              #+#    #+#             */
/*   Updated: 2021/08/11 19:22:11 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*achieve(void *arg)
{
	int			cnt;
	t_op		*op;

	cnt = 0;
	op = (t_op *)arg;
	while (true)
	{
		if (sem_wait(op->sem_c) == ERROR)
			sem_post(op->sem_t);
		if (++cnt && cnt == op->total)
		{
			console(op, FULL);
			sem_post(op->sem_t);
		}
	}
	return (NULL);
}

void	*monitor(void *arg)
{
	t_op		*op;
	long long	cur;

	op = (t_op *)arg;
	elapse(op, 0, op->time_die - 10);
	while (true)
	{
		if (!chrono(&cur))
			sem_post(op->sem_t);
		if (cur - op->philo[op->i].cur > (long long)op->time_die)
		{
			console(op, DEAD);
			sem_post(op->sem_t);
		}
	}
	return (NULL);
}

void	routine(t_op *op)
{
	if (pthread_create(&op->philo[op->i].th, NULL, monitor, (void *)op)
		|| pthread_detach(op->philo[op->i].th)
		|| !chrono(&op->philo[op->i].cur))
		sem_post(op->sem_t);
	while (true)
	{
		take_fork(op);
		philo_eat(op);
		put_fork(op);
		philo_sleep(op);
		philo_think(op);
	}
}
