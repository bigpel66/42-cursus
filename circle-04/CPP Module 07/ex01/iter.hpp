/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:28:06 by jseo              #+#    #+#             */
/*   Updated: 2021/10/14 15:43:11 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITER_H__
# define __ITER_H__

# include <cstddef>
# include <iostream>
# include <string>

template <typename T>
void										iter(T* arr, std::size_t len, void (*f)(const T&))
{
	for (std::size_t i = 0 ; i < len ; ++i)
		f(arr[i]);
	std::cout << std::endl;
}

template <typename T>
void										print(const T& arg)
{
	std::cout << arg << "\t";
}

#endif
