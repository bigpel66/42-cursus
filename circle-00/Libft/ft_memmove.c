/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 20:03:09 by jseo              #+#    #+#             */
/*   Updated: 2020/12/28 23:03:09 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = dst > src ? n + 1 : -1;
	if (dst != src && n)
	{
		if (dst > src)
			while (--i)
				((unsigned char *)dst)[i - 1] = ((unsigned char *)src)[i - 1];
		else
			while (++i < n)
				((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	}
	return (dst);
}
