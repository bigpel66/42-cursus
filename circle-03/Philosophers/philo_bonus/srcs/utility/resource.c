/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resource.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:51:58 by jseo              #+#    #+#             */
/*   Updated: 2021/08/11 18:27:21 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	take_fork(t_op *op)
{
	if (sem_wait(op->sem_f) == ERROR
		|| !console(op, GRAB)
		|| sem_wait(op->sem_f) == ERROR
		|| !console(op, GRAB))
		sem_post(op->sem_t);
}

void	put_fork(t_op *op)
{
	if (sem_post(op->sem_f) == ERROR
		|| sem_post(op->sem_f) == ERROR)
		sem_post(op->sem_t);
}
