/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jstrlcpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 17:52:21 by jseo              #+#    #+#             */
/*   Updated: 2021/06/19 17:53:42 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

size_t	jstrlcpy(char *dst, const char *src, size_t dstsize)
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
