/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:28:41 by jseo              #+#    #+#             */
/*   Updated: 2021/04/21 15:28:43 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	rand_double(void)
{
	static int	seed;

	seed = (seed * 1103515245 + 12345) & 0x7fffffff;
	return ((double)seed / (double)0x80000000);
}

double	rand_double_range(double min, double max)
{
	return ((rand_double() * (max - min)) + min);
}
