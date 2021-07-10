/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:39:54 by jseo              #+#    #+#             */
/*   Updated: 2021/07/10 13:00:29 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	qwordlen(const char *s)
{
	size_t	cnt;
	t_mode	mode;

	cnt = 0;
	while (*s && jisspace(*s))
		++s;
	if (*s && ++cnt)
		while (*s && !jisspace(*s))
			++s;
	while (*s)
	{
		mode = qcheck(*s, *(s + 1));
		qshift((char **)&s, mode);
		if (mode == BL || mode == NAN)
			qtrace((char **)&s, &cnt, mode, qdiff);
		else if (mode == SQ || mode == DQ)
			qtrace((char **)&s, &cnt, mode, qequal);
		else if (mode == ESQ || mode == EDQ)
			qtrace((char **)&s, &cnt, mode, qequal);
		qshift((char **)&s, mode);
	}
	return (cnt);
}

static char	**qwordfree(char **s, int i)
{
	while (--i >= 0 && s[i])
		jfree((void **)(&(s[i])));
	jfree((void **)(&s));
	return (NULL);
}

char	**qwordout(const char *s, char **buf, int i)
{
	char	*from;
	t_mode	mode;

	while (*s)
	{
		mode = qcheck(*s, *(s + 1));
		qshift((char **)&s, mode);
		from = (char *)s;
		if (mode == BL || mode == NAN)
			qtrace((char **)&s, NULL, mode, qdiff);
		else if (mode == SQ || mode == DQ)
			qtrace((char **)&s, NULL, mode, qequal);
		else if (mode == ESQ || mode == EDQ)
			qtrace((char **)&s, NULL, mode, qequal);
		if (mode != BL)
		{
			buf[i] = jsubstr(from, 0, s - from);
			if (!buf[i++])
				return (qwordfree(buf, i));
		}
		qshift((char **)&s, mode);
	}
	buf[i] = NULL;
	return (buf);
}

char	**qsplit(const char *s)
{
	int		i;
	char	*from;
	char	**buf;

	i = 0;
	if (!s || !jcalloc((void **)(&buf), qwordlen(s) + 1, sizeof(char *)))
		return (NULL);
	while (*s && jisspace(*s))
		++s;
	if (*s)
	{
		from = (char *)s;
		while (*s && !jisspace(*s))
			++s;
		buf[i] = jsubstr(from, 0, (s - from));
		if (!buf[i++])
			return (qwordfree(buf, i));
	}
	return (qwordout(s, buf, i));
}
