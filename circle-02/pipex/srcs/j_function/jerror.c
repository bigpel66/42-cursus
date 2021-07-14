/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jerror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:51:51 by jseo              #+#    #+#             */
/*   Updated: 2021/07/14 23:27:50 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	jerror(const char *s1, const char *s2)
{
	if (s1 && !s2)
		jputendl((char *)s1, STDERR_FILENO);
	else
	{
		jputstr((char *)s1, STDERR_FILENO);
		jputendl((char *)s2, STDERR_FILENO);
	}
}
