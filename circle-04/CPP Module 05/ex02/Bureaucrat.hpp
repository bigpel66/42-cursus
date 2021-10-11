/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:52:41 by jseo              #+#    #+#             */
/*   Updated: 2021/10/12 02:29:53 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_H__
# define __BUREAUCRAT_H__

# include <exception>
# include <iostream>
# include <string>

# define GRADE_MAX							1
# define GRADE_MIN							150

class Form;

class Bureaucrat
{
	private:
		const std::string					_name;
		int									_grade;

		Bureaucrat(void);

	public:
		class GradeTooHighException
			:	public std::exception
		{
			public:
				const char* what(void) const throw();
		};

		class GradeTooLowException
			:	public std::exception
		{
			public:
				const char* what(void) const throw();
		};

		const std::string&					getName(void) const;
		const int&							getGrade(void) const;

		int&								incrementGrade(void);
		int&								decrementGrade(void);

		void								signForm(const Form& f) const;

		Bureaucrat&							operator=(const Bureaucrat& b);
		Bureaucrat(const Bureaucrat& b);
		Bureaucrat(const std::string& name, const int& grade);
		~Bureaucrat(void);
};

std::ostream&								operator<<(std::ostream& o, const Bureaucrat& b);

#endif
