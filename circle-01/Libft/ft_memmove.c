/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 20:03:09 by jseo              #+#    #+#             */
/*   Updated: 2020/12/25 18:49:41 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	int	i;

	i = dst > src ? n : -1;
	if (dst != src && n)
	{
		if (dst > src)
			while (--i >= 0)
				((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		else
			while (++i < (int)n)
				((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	}
	return (dst);
}
