/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:10:13 by jseo              #+#    #+#             */
/*   Updated: 2021/10/14 15:27:19 by jseo             ###   ########.fr       */
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
const T&								max(T& a, T& b)
{
	return (a > b ? a : b);
}

template <typename T>
void									test(T a, T b)
{
	std::cout << "a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << min(a, b) << std::endl;
	std::cout << "max(a, b) = " << max(a, b) << std::endl;
	std::cout << std::endl;
}

#endif
