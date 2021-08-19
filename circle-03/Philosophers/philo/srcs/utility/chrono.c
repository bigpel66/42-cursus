/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chrono.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 15:27:26 by jseo              #+#    #+#             */
/*   Updated: 2021/08/12 12:55:59 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	chrono(long long *val)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == ERROR)
		return (false);
	*val = (long long)(tv.tv_sec * MILLI + tv.tv_usec / MILLI);
	return (true);
}

void	elapse(t_philo *philo, long long begin, long long limit)
{
	long long	cur;

	if (!begin)
		if (!chrono(&begin))
			pthread_mutex_unlock(&philo->op->t);
	while (true)
	{
		if (!chrono(&cur))
			pthread_mutex_unlock(&philo->op->t);
		if (cur - begin >= limit)
			break ;
		if (usleep(EPSILON) == ERROR)
			pthread_mutex_unlock(&philo->op->t);
	}
}
