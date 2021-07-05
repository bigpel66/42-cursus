/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jsplit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:45:48 by jseo              #+#    #+#             */
/*   Updated: 2021/07/05 18:23:48 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	jwordlen(const char *s, int c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != (char)c)
		{
			++cnt;
			while (*s && *s != (char)c)
				++s;
		}
		else
			++s;
	}
	return (cnt);
}

static char	**jwordfree(char **s, int i)
{
	while (--i >= 0 && s[i])
		jfree((void **)(&(s[i])));
	jfree((void **)(&s));
	return (NULL);
}

char	**jsplit(const char *s, int c)
{
	int		i;
	char	*from;
	char	**buf;

	i = 0;
	if (!s || !jcalloc((void **)(&buf), jwordlen(s, c) + 1, sizeof(char *)))
		return (NULL);
	while (*s)
	{
		if (*s != (char)c)
		{
			from = (char *)s;
			while (*s && *s != (char)c)
				++s;
			buf[i] = jsubstr(from, 0, (s - from));
			if (!buf[i++])
				return (jwordfree(buf, i));
		}
		else
			++s;
	}
	buf[i] = NULL;
	return (buf);
}
