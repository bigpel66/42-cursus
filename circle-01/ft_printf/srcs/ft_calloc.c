/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:24:54 by jseo              #+#    #+#             */
/*   Updated: 2021/03/17 12:24:56 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_calloc(size_t cnt, size_t n)
{
	void	*buf;

	if (!(buf = (void *)malloc(cnt * n)))
		return (NULL);
	ft_memset(buf, 0, cnt * n);
	return (buf);
}
