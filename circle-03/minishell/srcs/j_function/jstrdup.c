/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jstrdup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 00:48:46 by jseo              #+#    #+#             */
/*   Updated: 2021/12/22 17:49:40 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
