/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jfree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:04:31 by jseo              #+#    #+#             */
/*   Updated: 2021/08/11 15:50:38 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	jfree(void **ptr)
{
	if (!(ptr && *ptr))
		return ;
	free(*ptr);
	*ptr = NULL;
}
