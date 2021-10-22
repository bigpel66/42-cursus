/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:25:31 by jseo              #+#    #+#             */
/*   Updated: 2021/10/23 03:24:03 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
#include <cctype>

char										Convert::toChar(void) const
{
	return (static_cast<char>(_value));
}

int											Convert::toInt(void) const
{
	return (static_cast<int>(_value));
}

float										Convert::toFloat(void) const
{
	return (static_cast<float>(_value));
}

double										Convert::toDouble(void) const
{
	return (static_cast<double>(_value));
}

bool										Convert::getError(void) const
{
	return (_e);
}

const double& 							Convert::getValue(void) const
{
	return (_value);
}

const std::string&							Convert::getInput(void) const
{
	return (_input);
}

Convert&									Convert::operator=(const Convert& c)
{
	if (this != &c)
	{
		_e = c.getError();
		*(const_cast<std::string*>(&_input)) = c.getInput();
		*(const_cast<double*>(&_value)) = c.getValue();
	}
	return (*this);
}

Convert::Convert(void)
	:	_e(false), _input(""), _value(0.0) {}

Convert::Convert(const std::string& input)
	:	_e(false), _input(input), _value(0.0)
{
	try
	{
		char		*ptr = NULL;
		*(const_cast<double*>(&_value)) = std::strtod(_input.c_str(), &ptr);
		if (_value == 0.0 && (_input[0] != '-' && _input[0] != '+' && !std::isdigit(_input[0])))
			throw (std::bad_alloc());
		if (*ptr && std::strcmp(ptr, "f"))
			throw (std::bad_alloc());
	}
	catch (std::exception&)
	{
		_e = true;
	}
}

Convert::Convert(const Convert& c)
	:	_e(false), _input(c.getInput()), _value(c.getValue()) {}

Convert::~Convert(void) {}

static void									printToChar(std::ostream& o, const Convert& c)
{
	o << "char: ";
	if (std::isnan(c.getValue()) || std::isinf(c.getValue()))
		o << C_NP << std::endl;
	else if (std::isprint(c.toChar()))
		o << "'" << c.toChar() << "'" << std::endl;
	else
	 	o << C_ND << std::endl;
}

static void									printToInt(std::ostream& o, const Convert& c)
{
	o << "int: ";
	if (std::isnan(c.getValue()) || std::isinf(c.getValue()))
		o << C_NP << std::endl;
	else
		o << c.toInt() << std::endl;
}

static void									printToReal(std::ostream& o, const Convert& c)
{
	if (std::isnan(c.getValue()) || std::isinf(c.getValue()))
	{
		o << "float: " << std::showpos << c.toFloat() << "f" << std::endl;
		o << "double: " << std::showpos << c.toDouble() << std::endl;
		return ;
	}
	if (c.toFloat() == static_cast<long long>(c.toFloat()))
		o << "float: " << c.toFloat() << ".0f" << std::endl;
	else
	 	o << "float: " << std::setprecision(std::numeric_limits<float>::digits10) << c.toFloat() << "f" << std::endl;
	if (c.toDouble() == static_cast<long long>(c.toDouble()))
		o << "double: " << c.toDouble() << ".0" << std::endl;
	else
		o << "double: " << std::setprecision(std::numeric_limits<double>::digits10) << c.toDouble() << std::endl;
}

std::ostream&								operator<<(std::ostream& o, const Convert& c)
{
	if (c.getError())
	{
		o << "Converting Failed (Bad Alloc)" << std::endl;
		return (o);
	}
	printToChar(o, c);
	printToInt(o, c);
	printToReal(o, c);
	return (o);
}
