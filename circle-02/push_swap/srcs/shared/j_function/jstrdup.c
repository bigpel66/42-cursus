/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jstrdup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 17:49:56 by jseo              #+#    #+#             */
/*   Updated: 2021/06/19 17:53:46 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

char	*jstrdup(const char *s)
{
	size_t	len;
	char	*buf;

	if (!s)
		return (NULL);
	len = jstrlen(s);
	buf = (char *)malloc(len + 1);
	if (!buf)
		return (NULL);
	jstrlcpy(buf, s, len + 1);
	return (buf);
}
