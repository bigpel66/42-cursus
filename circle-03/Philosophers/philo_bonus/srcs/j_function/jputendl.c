/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jputendl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 01:23:16 by jseo              #+#    #+#             */
/*   Updated: 2021/08/11 15:50:49 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	jputendl(char *s, int fd)
{
	if (!s)
		return ;
	jputstr(s, fd);
	jputchar('\n', fd);
}