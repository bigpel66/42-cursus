/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:04:51 by jseo              #+#    #+#             */
/*   Updated: 2021/10/14 18:18:00 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY_H__
# define __ARRAY_H__

# include <cstddef>
# include <exception>
# include <iostream>

template <typename T>
class Array
{
	private:
		std::size_t						_size;
		T*								_data;

	public:
		class OutofRange
			:	public std::exception
		{
			public:
				const char* what(void) const throw()
				{
					return ("Out of Range");
				}
		};

		size_t							size(void) const
		{
			return (_size);
		}

		T&								operator[](std::size_t i)
		{
			if (i >= _size)
				throw (OutofRange());
			return (_data[i]);
		}

		const T&						operator[](std::size_t i) const
		{
			if (i >= _size)
				throw (OutofRange());
			return (_data[i]);
		}

		Array&							operator=(const Array& a)
		{
			if (this != &a)
			{
				if (_size)
				{
					delete[] _data;
					_data = NULL;
					_size = 0;
				}
				_size = a.size();
				if (_size)
					_data = new T[_size];
				for (std::size_t i = 0 ; i < _size ; ++i)
					_data[i] = a[i];
			}
			return (*this);
		}

		Array(void)
			:	_size(0), _data(NULL) {}

		Array(std::size_t n)
			:	_size(n), _data(NULL)
		{
			if (_size)
				_data = new T[_size];
		}

		Array(const Array& a)
			:	_size(a.size()), _data(NULL)
		{
			if (_size)
				_data = new T[_size];
			for (std::size_t i = 0 ; i < _size ; ++i)
				_data[i] = a[i];
		}

		~Array(void)
		{
			if (_size)
			{
				delete[] _data;
				_data = NULL;
				_size = 0;
			}
		}
};

template <typename T>
void									test(std::size_t size)
{
	Array<T>		a(size);

	std::cout << "Value Testing Ascending" << std::endl;
	for (std::size_t i = 0 ; i < size ; ++i)
	{
		a[i] = static_cast<T>(i + '0');
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Value Testing Descending" << std::endl;
	for (std::size_t i = 0 ; i < size ; ++i)
	{
		a[i] = static_cast<T>(size - i - 1 + '0');
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Exception Testing" << std::endl;
	try
	{
		std::cout << a[size] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

#endif
