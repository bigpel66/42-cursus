/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:21:19 by jseo              #+#    #+#             */
/*   Updated: 2021/10/15 15:37:40 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASY_FIND_H__
# define __EASY_FIND_H__

# include <algorithm>
# include <deque>
# include <iostream>
# include <list>
# include <stdexcept>
# include <vector>

template <typename T>
typename T::iterator						easyfind(T& container, int value)
{
	typename T::iterator iter = std::find(std::begin(container), std::end(container), value);
	if (iter == std::end(container))
		throw (std::runtime_error(std::string("Value ") + std::to_string(value) + std::string(" is not in Container")));
	return (iter);
}

template <typename T, typename... Arg>
void										test(T& container, int value, Arg... args)
{
	container = T{args...};
	try
	{
		typename T::iterator iter = easyfind(container, value);
		std::cout << "Value " << value << " found on Index " << std::distance(std::begin(container), iter) << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

#endif
