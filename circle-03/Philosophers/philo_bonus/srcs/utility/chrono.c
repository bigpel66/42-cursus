/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chrono.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:52:01 by jseo              #+#    #+#             */
/*   Updated: 2021/08/11 18:05:44 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	chrono(long long *val)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == ERROR)
		return (false);
	*val = (long long)(tv.tv_sec * MILLI + tv.tv_usec / MILLI);
	return (true);
}

void	elapse(t_op *op, long long begin, long long limit)
{
	long long		cur;

	if (!begin)
		if (!chrono(&begin))
			sem_post(op->sem_t);
	while (true)
	{
		if (!chrono(&cur))
			sem_post(op->sem_t);
		if (cur - begin >= limit)
			break ;
		if (usleep(EPSILON) == ERROR)
			sem_post(op->sem_t);
	}
}
