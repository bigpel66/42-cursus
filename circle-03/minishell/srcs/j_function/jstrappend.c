/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jstrappend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:57:06 by jseo              #+#    #+#             */
/*   Updated: 2021/07/07 19:57:17 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	jstrappend(char **s, char *s2)
{
	char	*s1;

	if (!*s)
	{
		*s = jstrdup(s2);
		if (!*s)
			return (false);
		return (true);
	}
	s1 = jstrdup(*s);
	jfree((void **)s);
	if (!s1)
		return (false);
	if (!jcalloc((void **)s, jstrlen(s1) + jstrlen(s2) + 1, 1))
	{
		jfree((void **)(&s1));
		return (false);
	}
	jstrlcpy(*s, s1, jstrlen(s1) + 1);
	jstrlcpy(*s + jstrlen(s1), s2, jstrlen(s2) + 1);
	jfree((void **)(&s1));
	return (true);
}
