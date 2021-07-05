/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jsubstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:10:57 by jseo              #+#    #+#             */
/*   Updated: 2021/07/05 18:47:53 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*jsubstr(const char *s, unsigned int start, size_t len)
{
	char	*buf;
	size_t	src;
	size_t	dst;

	src = jstrlen(s);
	dst = len;
	if (dst > src)
		dst = src;
	if (!s || !jcalloc((void **)(&buf), dst + 1, sizeof(char)))
		return (NULL);
	if ((size_t)start < src)
		jstrlcpy(buf, s + start, dst + 1);
	return (buf);
}
