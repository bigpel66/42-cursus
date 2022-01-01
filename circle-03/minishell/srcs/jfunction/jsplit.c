/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jsplit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:45:48 by jseo              #+#    #+#             */
/*   Updated: 2022/01/01 12:39:29 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jfunction.h"

static inline char	**wordfree(char **s, int i)
{
	while (--i >= 0 && s[i])
		jfree((void **)(&(s[i])));
	jfree((void **)(&s));
	return (NULL);
}

char	**jsplit(const char *s, bool (*cmp)(int))
{
	int		i;
	char	*from;
	char	**buf;

	i = 0;
	if (!s || !jcalloc((void **)(&buf), jwordlen(s, cmp) + 1, sizeof(char *)))
		return (NULL);
	while (*s)
	{
		if (!cmp(*s))
		{
			from = (char *)s;
			while (*s && !cmp(*s))
				++s;
			buf[i] = jsubstr(from, 0, (s - from));
			if (!buf[i++])
				return (wordfree(buf, i));
		}
		else
			++s;
	}
	buf[i] = NULL;
	return (buf);
}
