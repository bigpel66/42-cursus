/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:41:15 by jseo              #+#    #+#             */
/*   Updated: 2020/12/28 22:53:15 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	char	*buf;

	i = -1;
	buf = dst;
	while (++i < len)
	{
		*dst = *src;
		if (*src)
			++src;
		++dst;
	}
	return (buf);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buf;

	if (!s || !(buf = (char *)malloc(len + 1)))
		return (NULL);
	if (start < (unsigned int)ft_strlen(s))
		ft_strncpy(buf, s + start, len);
	buf[len] = '\0';
	return (buf);
}
