/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:32:48 by jseo              #+#    #+#             */
/*   Updated: 2020/12/24 19:50:50 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wordlen(char const *s, char c)
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
		++s;
	}
	return (cnt);
}

char		**ft_free_dptr(char **s, int i)
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

char		**ft_split(char const *s, char c)
{
	int		i;
	int		cnt;
	char	*from;
	char	**res;

	i = 0;
	cnt = (int)ft_wordlen(s, c);
	if (!(buf = (char **)malloc(cnt + 1)))
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			from = s;
			while (*s && *s != c)
				++s;
			if (!(buf[i++] = ft_substr(from, 0, (s - from))))
				return (ft_free_arr(buf, i));
		}
		++s;
	}
	buf[i] = '\0';
	return (buf);
}
