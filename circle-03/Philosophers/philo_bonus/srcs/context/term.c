/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:52:14 by jseo              #+#    #+#             */
/*   Updated: 2021/08/23 15:32:33 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	free_arg(t_op *op)
{
	int		i;

	sem_unlink(op->f);
	sem_unlink(op->t);
	sem_unlink(op->p);
	sem_unlink(op->c);
	i = -1;
	while (++i < op->total)
	{
		kill(op->philo[i].pid, SIGKILL);
		waitpid(op->philo[i].pid, NULL, WNOHANG);
	}
	jfree((void **)(&op->philo));
}

t_exit	exit_invalid(t_op *op, void (*f)(void))
{
	if (f)
		f();
	free_arg(op);
	return (INVALID);
}

t_exit	exit_valid(t_op *op)
{
	free_arg(op);
	return (VALID);
}
