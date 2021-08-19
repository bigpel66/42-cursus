/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 19:13:01 by jseo              #+#    #+#             */
/*   Updated: 2021/08/12 10:24:50 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *arg)
{
	t_philo		*philo;
	long long	cur;

	philo = (t_philo *)arg;
	elapse(philo, 0, philo->op->time_die - 10);
	while (true)
	{
		if (!chrono(&cur))
			pthread_mutex_unlock(&philo->op->t);
		if (cur - philo->cur > (long long)philo->op->time_die)
		{
			console(philo, DEAD);
			pthread_mutex_unlock(&philo->op->t);
		}
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->i % 2)
		elapse(philo, 0, EPSILON * 10);
	if (!chrono(&philo->cur))
		pthread_mutex_unlock(&philo->op->t);
	while (true)
	{
		take_fork(philo);
		philo_eat(philo);
		put_fork(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}
