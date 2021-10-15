/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 11:46:59 by jseo              #+#    #+#             */
/*   Updated: 2021/10/15 12:29:41 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <algorithm>

const char*									Span::CannotStoreException::what(void) const throw()
{
	return ("Not Enough Capacity");
}

const char*									Span::CannotSpanException::what(void) const throw()
{
	return ("Not Enough Element");
}

const std::vector<int>&						Span::getData(void) const
{
	return (_data);
}

void										Span::addNumber(int value)
{
	if (_data.size() == _data.capacity())
		throw (CannotStoreException());
	_data.push_back(value);
}

std::size_t									Span::shortestSpan(void)
{
	if (_data.size() < 2)
		throw (CannotSpanException());
	std::vector<int *>	v_ptr;
	v_ptr.reserve(_data.capacity());
	std::for_each(std::begin(_data), std::end(_data), [&v_ptr] (int& i) { v_ptr.push_back(&i); });
	std::sort(std::begin(v_ptr), std::end(v_ptr), [] (const int* i, const int* j) { return (*i < *j); });
	return (*(v_ptr.at(1)) - *(v_ptr.at(0)));
}

std::size_t									Span::longestSpan(void)
{
	if (_data.size() < 2)
		throw (CannotSpanException());
	auto p_iter = std::minmax_element(std::begin(_data), std::end(_data));
	return (*(p_iter.second) - *(p_iter.first));
}

Span&										Span::operator=(const Span& s)
{
	if (_data.capacity() != s.getData().capacity())
		return (*this);
	if (this != &s)
	{
		_data.clear();
		_data.reserve(s.getData().capacity());
		std::copy(std::begin(s.getData()), std::end(s.getData()), std::back_inserter(_data));
	}
	return (*this);
}

Span::Span(void)
	:	_data(0, 0)
{
	_data.reserve(0);
}

Span::Span(std::size_t n)
	:	_data(0, 0)
{
	_data.reserve(n);
}

Span::Span(const Span& s)
	: _data(0, 0)
{
	_data.reserve(s.getData().capacity());
	std::copy(std::begin(s.getData()), std::end(s.getData()), std::back_inserter(_data));
}

Span::~Span(void) {}
