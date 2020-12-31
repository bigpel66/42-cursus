/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 20:09:41 by jseo              #+#    #+#             */
/*   Updated: 2020/12/31 16:21:15 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	len;

	if (!src)
		return (0);
	srcsize = ft_strlen(src);
	len = srcsize >= dstsize ? dstsize - 1 : srcsize;
	if (dstsize)
	{
		ft_memcpy(dst, src, len);
		dst[len] = '\0';
	}
	return (srcsize);
}
