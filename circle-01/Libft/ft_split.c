/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:32:48 by jseo              #+#    #+#             */
/*   Updated: 2020/12/26 23:26:51 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordlen(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			++cnt;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (cnt);
}

char	**ft_free_dptr(char **s, int i)
{
	while (--i >= 0 && s[i])
	{
		free(s[i]);
		s[i] = NULL;
	}
	free(s);
	s = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	*from;
	char	**buf;

	i = 0;
	if (!s || !(buf = (char **)malloc((ft_wordlen(s, c) + 1) * sizeof(char *))))
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			from = (char *)s;
			while (*s && *s != c)
				++s;
			if (!(buf[i++] = ft_substr(from, 0, (s - from))))
				return (ft_free_dptr(buf, i));
		}
		else
			++s;
	}
	buf[i] = NULL;
	return (buf);
}
