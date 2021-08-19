/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resource.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 16:15:46 by jseo              #+#    #+#             */
/*   Updated: 2021/08/12 10:05:09 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->op->f[philo->l])
		|| !console(philo, GRAB)
		|| pthread_mutex_lock(&philo->op->f[philo->r])
		|| !console(philo, GRAB))
		pthread_mutex_unlock(&philo->op->t);
}

void	put_fork(t_philo *philo)
{
	if (pthread_mutex_unlock(&philo->op->f[philo->l])
		|| pthread_mutex_unlock(&philo->op->f[philo->r]))
		pthread_mutex_unlock(&philo->op->t);
}
