/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jstrdup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 00:48:46 by jseo              #+#    #+#             */
/*   Updated: 2021/12/26 22:56:04 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jfunction.h"

char	*jstrdup(const char *s)
{
	size_t	len;
	char	*buf;

	len = jstrlen(s);
	if (!jcalloc((void **)(&buf), len + 1, sizeof(char)))
		return (NULL);
	jstrlcpy(buf, s, len + 1);
	return (buf);
}
