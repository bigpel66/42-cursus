/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jargs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 15:18:49 by jseo              #+#    #+#             */
/*   Updated: 2021/07/08 17:51:32 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	jwordlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (!quote(*s) && !jisspace(*s))
		{
			while (*s && !jisspace(*s))
				++s;
			++cnt;
		}
		else if (jisspace(*s))
			++s;
		else
		{
			while (*(++s) && !quote(*s))
				;
			++s;
			++cnt;
		}
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

static bool	jnormal(char **buf, const char **s)
{
	char	*from;

	from = (char *)*s;
	while (**s && !jisspace(**s))
		++(*s);
	*buf = jsubstr(from, 0, *s - from);
	if (!*buf)
		return (false);
	return (true);
}

static bool	jquote(char **buf, const char **s)
{
	char	*from;

	from = (char *)(++*s);
	while (*(++(*s)) && !quote(**s))
		;
	*buf = jsubstr(from, 0, *s - from);
	++(*s);
	if (!*buf)
		return (false);
	return (true);
}

char	**jargs(const char *s)
{
	int		i;
	char	**buf;

	i = 0;
	if (!s || !jcalloc((void **)(&buf), jwordlen(s) + 1, sizeof(char *)))
		return (NULL);
	while (*s)
	{
		if (!quote(*s) && !jisspace(*s))
		{
			if (!jnormal(&(buf[i++]), &s))
				return (jwordfree(buf, i));
		}
		else if (jisspace(*s))
			++s;
		else
		{
			if (!jquote(&(buf[i++]), &s))
				return (jwordfree(buf, i));
		}
	}
	buf[i] = NULL;
	return (buf);
}
