/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:02:59 by jseo              #+#    #+#             */
/*   Updated: 2021/02/12 18:09:35 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	if (dstsize)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
	}
	while (src[i])
		++i;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*buf;

	len = ft_strlen(s);
	if (!(buf = (char *)malloc(len + 1)))
		return (NULL);
	ft_strlcpy(buf, s, len + 1);
	return (buf);
}

char	*ft_strappend(char *s1, char *s2)
{
	char	*s;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
		return (!s1 ? ft_strdup(s2) : s1);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(s = (char *)malloc(i + j + 1)))
		return (NULL);
	ft_strlcpy(s, s1, i + 1);
	ft_strlcpy(s + i, s2, j + 1);
	free(s1);
	return (s);
}
