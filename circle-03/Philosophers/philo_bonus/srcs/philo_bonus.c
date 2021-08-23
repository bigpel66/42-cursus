/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:49:09 by jseo              #+#    #+#             */
/*   Updated: 2021/08/23 15:28:37 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	usage(void)
{
	static const char	*s1 = "usage : ./philo number_of_philosophers";
	static const char	*s2 = " time_to_die time_to_eat time_to_sleep ";
	static const char	*s3 = "[number_of_times_each_philosopher_must_eat]";

	jputstr((char *)s1, STDERR_FILENO);
	jputstr((char *)s2, STDERR_FILENO);
	jputendl((char *)s3, STDERR_FILENO);
}

static void	process(void)
{
	static const char	*s1 = "error : something went wrong";
	static const char	*s2 = "tasks related to the process can be wrong";

	jputendl((char *)s1, STDERR_FILENO);
	jputendl((char *)s2, STDERR_FILENO);
}

static bool	meals_ready_to_eat(int ac, char **av, t_op *op)
{
	op->f = "/sem_fork";
	op->t = "/sem_term";
	op->p = "/sem_print";
	op->c = "/sem_count";
	if (!jatoi(&av[1], &op->total) || !jatoi(&av[2], &op->time_die)
		|| !jatoi(&av[3], &op->time_eat) || !jatoi(&av[4], &op->time_nap))
		return (false);
	if (ac == 6 && !jatoi(&av[5], &op->limit))
		return (false);
	if (!jcalloc((void **)(&op->philo), op->total, sizeof(t_philo)))
		return (false);
	if (!semaphore(&op->sem_f, op->f, op->total)
		|| !semaphore(&op->sem_t, op->t, 0)
		|| !semaphore(&op->sem_p, op->p, 1)
		|| !semaphore(&op->sem_c, op->c, 0))
		return (false);
	return (true);
}

static bool	meals_iterate_to_eat(t_op *op)
{
	int					i;

	i = -1;
	if (pthread_create(&op->th, NULL, achieve, (void *)op)
		|| pthread_detach(op->th) || !chrono(&op->begin))
		return (false);
	while (++i < op->total)
	{
		op->i = i;
		op->philo[i].pid = fork();
		if (op->philo[i].pid == ERROR)
			return (false);
		else if (!op->philo[i].pid)
		{
			routine(op);
			exit(VALID);
		}
	}
	if (sem_wait(op->sem_t) == ERROR)
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	t_op	op;

	jmemset(&op, 0, sizeof(t_op));
	if (ac < 5 || ac > 6 || !meals_ready_to_eat(ac, av, &op))
		return (exit_invalid(&op, usage));
	if (!meals_iterate_to_eat(&op))
		return (exit_invalid(&op, process));
	return (exit_valid(&op));
}
