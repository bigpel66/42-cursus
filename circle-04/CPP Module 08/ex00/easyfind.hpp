/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:21:19 by jseo              #+#    #+#             */
/*   Updated: 2021/10/15 15:59:16 by jseo             ###   ########.fr       */
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

template <typename C>
typename C::iterator						easyfind(C& container, int value)
{
	typename C::iterator iter = std::find(std::begin(container), std::end(container), value);
	if (iter == std::end(container))
		throw (std::runtime_error(std::string("Value ") + std::to_string(value) + std::string(" is not in C")));
	return (iter);
}

template <typename C, typename... Arg>
void										test(C& container, int value, Arg... args)
{
	container = C{args...};
	try
	{
		typename C::iterator iter = easyfind(container, value);
		std::cout << "Value " << value << " found on Index " << std::distance(std::begin(container), iter) << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

#endif
