/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:08:30 by jseo              #+#    #+#             */
/*   Updated: 2021/10/11 21:49:16 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char*									Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade Too High");
}

const char*									Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade Too Low");
}

const std::string&							Bureaucrat::getName(void) const
{
	return (_name);
}

const int&									Bureaucrat::getGrade(void) const
{
	return (_grade);
}

int&										Bureaucrat::incrementGrade(void)
{
	if (_grade - 1 < GRADE_MAX)
		throw GradeTooHighException();
	return (--_grade);
}

int&										Bureaucrat::decrementGrade(void)
{
	if (_grade + 1 > GRADE_MIN)
		throw GradeTooLowException();
	return (++_grade);
}

Bureaucrat&									Bureaucrat::operator=(const Bureaucrat& b)
{
	if (this != &b)
	{
		*(const_cast<std::string*>(&_name)) = b.getName();
		_grade = b.getGrade();
	}
	return (*this);
}

Bureaucrat::Bureaucrat(void) {}

Bureaucrat::Bureaucrat(const Bureaucrat& b)
	:	_name(b.getName()), _grade(b.getGrade())
{
	if (_grade < GRADE_MAX)
		throw GradeTooHighException();
	if (_grade > GRADE_MIN)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const std::string& name, const int& grade)
	:	_name(name), _grade(grade)
{
	if (_grade < GRADE_MAX)
		throw GradeTooHighException();
	if (_grade > GRADE_MIN)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat(void) {}

std::ostream&								operator<<(std::ostream& o, const Bureaucrat& b)
{
	return (o << "<" << b.getName() << ">, bureaucrat grade <" << b.getGrade() << ">");
}
