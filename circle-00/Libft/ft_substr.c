/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:41:15 by jseo              #+#    #+#             */
/*   Updated: 2020/12/30 12:00:27 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buf;

	if (!s || !(buf = (char *)malloc(len + 1)))
		return (NULL);
	if ((size_t)start >= ft_strlen(s) || !(ft_strlcpy(buf, s + start, len + 1)))
		buf[0] = '\0';
	return (buf);
}
