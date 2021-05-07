/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:59:26 by jseo              #+#    #+#             */
/*   Updated: 2021/05/07 17:10:06 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*buf;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	buf = (char *)malloc(len + 1);
	if (!buf)
		return (NULL);
	ft_strlcpy(buf, s, len + 1);
	return (buf);
}

t_bool	ft_strappend(char **s, char *s1, char *s2)
{
	char	*tmp;

	if (!s1 && !s2)
		return (FALSE);
	if (!s1)
	{
		*s = ft_strdup(s2);
		if (!*s)
			return (FALSE);
		return (TRUE);
	}
	if (!s2)
	{
		*s = s1;
		return (TRUE);
	}
	if (!dalloc((void **)(&tmp), ft_strlen(s1) + ft_strlen(s2) + 1, 1))
	{
		free(s1);
		return (FALSE);
	}
	ft_strlcpy(tmp, s1, ft_strlen(s1) + 1);
	ft_strlcpy(tmp + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	free(s1);
	return (TRUE);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		((unsigned char *)s)[i] = (unsigned char)c;
	return (s);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if (dst != src && n)
		while (++i < n)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	return (dst);
}

t_bool	ft_memappend(void **s, void *s1, const void *s2, int i)
{
	unsigned char	*tmp;

	if (!dalloc((void **)(&tmp), BUFFER_SIZE * i, sizeof(unsigned char)))
	{
		free_ptr(&s1);
		return (FALSE);
	}
	ft_memcpy(tmp, s1, BUFFER_SIZE * (i - 1));
	ft_memcpy(tmp + BUFFER_SIZE * (i - 1), s2, BUFFER_SIZE);
	free_ptr(&s1);
	*(unsigned char **)s = tmp;
	return (TRUE);
}
