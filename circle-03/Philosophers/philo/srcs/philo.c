/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:41:30 by jseo              #+#    #+#             */
/*   Updated: 2021/08/12 10:25:02 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	usage(void)
{
	static const char	*s1 = "usage : ./philo number_of_philosophers";
	static const char	*s2 = " time_to_die time_to_eat time_to_sleep ";
	static const char	*s3 = "[number_of_times_each_philosopher_must_eat]";

	jputstr((char *)s1, STDERR_FILENO);
	jputstr((char *)s2, STDERR_FILENO);
	jputendl((char *)s3, STDERR_FILENO);
}

static void	pthread(void)
{
	static const char	*s1 = "error : something went wrong";
	static const char	*s2 = "create, detach, join process can be wrong";

	jputendl((char *)s1, STDERR_FILENO);
	jputendl((char *)s2, STDERR_FILENO);
}

static bool	meals_ready_to_eat(int ac, char **av, t_op *op, t_philo **philo)
{
	int		i;

	if (!jatoi(&av[1], &op->total) || !jatoi(&av[2], &op->time_die)
		|| !jatoi(&av[3], &op->time_eat) || !jatoi(&av[4], &op->time_nap))
		return (false);
	if (ac == 6 && !jatoi(&av[5], &op->limit))
		return (false);
	if (!jcalloc((void **)(&op->f), op->total, sizeof(t_mu))
		|| !jcalloc((void **)(philo), op->total, sizeof(t_philo)))
		return (false);
	i = -1;
	while (++i < op->total)
		if (pthread_mutex_init(&op->f[i], NULL))
			return (false);
	if (pthread_mutex_init(&op->p, NULL)
		|| pthread_mutex_init(&op->t, NULL))
		return (false);
	return (true);
}

static bool	meals_iterate_to_eat(t_op *op, t_philo *philo)
{
	int		i;

	i = -1;
	if (pthread_mutex_lock(&op->t) || !chrono(&op->begin))
		return (false);
	while (++i < op->total)
	{
		philo[i].i = i;
		philo[i].op = op;
		philo[i].l = i;
		philo[i].r = (i + 1) % op->total;
		if (pthread_create(&philo[i].th, NULL, routine, (void *)(&philo[i]))
			|| pthread_detach(philo[i].th))
			return (false);
		if (pthread_create(&philo[i].mo, NULL, monitor, (void *)(&philo[i]))
			|| pthread_detach(philo[i].mo))
			return (false);
	}
	if (pthread_mutex_lock(&op->t))
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	t_op	op;
	t_philo	*philo;

	jmemset(&op, 0, sizeof(t_op));
	philo = NULL;
	if (ac < 5 || ac > 6 || !meals_ready_to_eat(ac, av, &op, &philo))
		return (exit_invalid(&op, &philo, usage));
	if (!meals_iterate_to_eat(&op, philo))
		return (exit_invalid(&op, &philo, pthread));
	return (exit_valid(&op, &philo));
}
