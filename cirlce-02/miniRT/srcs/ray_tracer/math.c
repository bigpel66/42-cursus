/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:28:41 by jseo              #+#    #+#             */
/*   Updated: 2021/04/22 14:41:59 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	randv(void)
{
	static int	seed;

	seed = (seed * 1103515245 + 12345) & 0x7fffffff;
	return ((double)seed / (double)0x80000000);
}

double	randr(double min, double max)
{
	return ((randv() * (max - min)) + min);
}

double	clamp(double d, double min, double max)
{
	if (d < min)
		return (min);
	if (d > max)
		return (max);
	return (d);
}

double	degrees_to_radians(double degrees)
{
	return (degrees * M_PI / 180.0);
}
