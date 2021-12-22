/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jstrjoin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 22:56:13 by jseo              #+#    #+#             */
/*   Updated: 2021/07/06 23:15:24 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*jstrjoin(const char *s1, const char *s2)
{
	char	*buf;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = jstrlen(s1);
	j = jstrlen(s2);
	if (!jcalloc((void **)(&buf), i + j + 1, sizeof(char)))
		return (NULL);
	jstrlcpy(buf, s1, i + 1);
	jstrlcpy(buf + i, s2, j + 1);
	return (buf);
}
