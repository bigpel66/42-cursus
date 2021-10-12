/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:08:30 by jseo              #+#    #+#             */
/*   Updated: 2021/10/12 13:25:51 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

const char*									Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat Grade Too High");
}

const char*									Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat Grade Too Low");
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

void										Bureaucrat::signForm(const Form& f) const
{
	try
	{
		(*const_cast<Form*>(&f)).beSigned(*this);
		std::cout << "<" << _name << "> signs <" << f.getName() << ">" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "<" << _name << "> cannot sign <" << f.getName() << "> because <" << e.what() << ">" << std::endl;
	}
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
