/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:51:56 by jseo              #+#    #+#             */
/*   Updated: 2021/08/11 18:33:15 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_eat(t_op *op)
{
	if (!console(op, EATING)
		|| !chrono(&op->philo[op->i].cur))
		sem_post(op->sem_t);
	++(op->philo[op->i].c);
	elapse(op, op->philo[op->i].cur, op->time_eat);
	if (op->limit && op->philo[op->i].c == op->limit)
		if (sem_post(op->sem_c) == ERROR)
			sem_post(op->sem_t);
}

void	philo_sleep(t_op *op)
{
	if (!console(op, SLEEPING))
		sem_post(op->sem_t);
	elapse(op, 0, op->time_nap);
}

void	philo_think(t_op *op)
{
	if (!console(op, THINKING))
		sem_post(op->sem_t);
}
