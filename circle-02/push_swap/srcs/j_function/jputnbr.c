/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jputnbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 10:53:01 by jseo              #+#    #+#             */
/*   Updated: 2021/06/11 10:53:03 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	jputnbr(int n, int fd)
{
	if (n == -2147483648)
	{
		jputnbr(n / 10, fd);
		jputchar(8 + '0', fd);
	}
	else if (n < 0)
	{
		jputchar('-', fd);
		jputnbr(-n, fd);
	}
	else
	{
		if (n > 9)
			jputnbr(n / 10, fd);
		jputchar(n % 10 + '0', fd);
	}
}
