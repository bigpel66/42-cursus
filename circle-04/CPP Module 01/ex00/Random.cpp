/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Random.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:57:42 by jseo              #+#    #+#             */
/*   Updated: 2021/10/10 19:58:39 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Random.hpp"

int				Random::seed = 0;

Random::Random(void) {}
Random::~Random(void) {}

double			Random::randv(void)
{
	seed = (seed * 1103515245 + 12345) & 0x7fffffff;
	return ((double)seed / (double)0x80000000);
}

double 			Random::randr(double min, double max)
{
	return ((randv() * (max - min)) + min);
}
