/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:10:13 by jseo              #+#    #+#             */
/*   Updated: 2021/10/14 15:24:26 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WHATEVER_H__
# define __WHATEVER_H__

# include <iostream>
# include <string>

template <typename T>
void									swap(T&	a, T& b)
{
	T		temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T>
const T&								min(T& a, T& b)
{
	return (a < b ? a : b);
}

template <typename T>
const T&								maa(T& a, T& b)
{
	return (a > b ? a : b);
}

template <typename T>
void									test(T a, T b)
{
	std::cout << "before swap: " << a << " " << b << std::endl;
	swap(a, b);
	std::cout << "after swap: " << a << " " << b << std::endl;
	std::cout << "min : " << min(a, b) << std::endl;
	std::cout << "max : " << maa(a, b) << std::endl;
	std::cout << std::endl;
}

#endif
