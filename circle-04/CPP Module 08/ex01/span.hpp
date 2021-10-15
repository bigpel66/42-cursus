/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 11:22:39 by jseo              #+#    #+#             */
/*   Updated: 2021/10/15 12:43:12 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN_H__
# define __SPAN_H__

# include <array>
# include <algorithm>
# include <cstddef>
# include <exception>
# include <iostream>
# include <vector>

class Span
{
	private:
		std::vector<int>				_data;

		Span(void);

	public:
		class CannotStoreException
			:	public std::exception
		{
			public:
				const char* what(void) const throw();
		};

		class CannotSpanException
			:	public std::exception
		{
			public:
				const char* what(void) const throw();
		};

		const std::vector<int>&			getData(void) const;

		void							addNumber(int value);

		template <typename T>
		void							addRange(T begin, T end)
		{
			if (std::distance(begin, end) > static_cast<long>(_data.capacity() - _data.size()))
				throw (CannotStoreException());
			while (begin != end)
				_data.push_back(*begin++);
		}

		std::size_t						shortestSpan(void);
		std::size_t						longestSpan(void);

		Span&							operator=(const Span& s);
		Span(std::size_t n);
		Span(const Span& s);
		~Span(void);
};

#endif
