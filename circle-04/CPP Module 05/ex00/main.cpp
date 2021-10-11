/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:26:14 by jseo              #+#    #+#             */
/*   Updated: 2021/10/11 21:50:04 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	try_catch_call(const Bureaucrat& b, int& (Bureaucrat::*f)(void))
{
	try
	{
		(*(const_cast<Bureaucrat*>(&b)).*f)();
		std::cout << b << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	try_catch_make(const std::string& name, const int& grade)
{
	try
	{
		Bureaucrat	b(name, grade);
		std::cout << b << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
int		main(void)
{
	Bureaucrat		j("Jseo", 1);
	Bureaucrat		h("Hyson", 150);

	std::cout << j << std::endl
				<< h << std::endl;
	std::cout << std::endl;
	try_catch_call(j, &Bureaucrat::incrementGrade);
	try_catch_call(h, &Bureaucrat::decrementGrade);
	std::cout << std::endl;
	try_catch_make("Jseo", 0);
	try_catch_make("Hyson", 151);
	std::cout << std::endl;
	try_catch_make("Jseo", 70);
	try_catch_make("Hyson", 70);
	std::cout << std::endl;
	try_catch_call(j, &Bureaucrat::decrementGrade);
	try_catch_call(h, &Bureaucrat::incrementGrade);
	std::cout << std::endl;
	try_catch_call(j, &Bureaucrat::decrementGrade);
	try_catch_call(h, &Bureaucrat::incrementGrade);
	return (0);
}
