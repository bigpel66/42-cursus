/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:12:29 by jseo              #+#    #+#             */
/*   Updated: 2021/08/11 19:38:09 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	semaphore(sem_t **sem, const char *file, size_t cnt)
{
	sem_unlink(file);
	*sem = sem_open(file, O_CREAT, 0644, cnt);
	if (*sem == SEM_FAILED)
		return (false);
	return (true);
}
