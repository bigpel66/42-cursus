/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:51:02 by jseo              #+#    #+#             */
/*   Updated: 2021/10/11 22:46:48 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_H__
# define __FORM_H__

# include "Bureaucrat.hpp"
# include <exception>
# include <string>

class Form
{
	private:
		const std::string					_name;
		const int							_sign_grade;
		const int							_exec_grade;
		bool								_signed;

		Form(void);

	public:
		class GradeTooHighException
			:	public std::exception
		{
			const char* what(void) const throw();
		};

		class GradeTooLowException
			:	public std::exception
		{
			const char* what(void) const throw();
		};

		const std::string&					getName(void) const;
		const int&							getSignGrade(void) const;
		const int&							getExecGrade(void) const;
		const bool&							getSigned(void) const;

		void								beSigned(const Bureaucrat& b);

		Form&								operator=(const Form& f);
		Form(const Form& f);
		Form(const std::string& name, const int& sign_grade, const int& exec_grade);
		~Form(void);
};

std::ostream&								operator<<(std::ostream& o, const Form& f);

#endif
