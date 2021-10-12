/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:51:02 by jseo              #+#    #+#             */
/*   Updated: 2021/10/12 14:04:58 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_H__
# define __FORM_H__

# include "Bureaucrat.hpp"
# include <exception>
# include <string>

# define F_NAME								"Form"

class Form
{
	private:
		static const std::string			_type;
		const std::string					_name;
		const int							_sign_grade;
		const int							_exec_grade;
		bool								_signed;

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

		class DoesNotSignedException
			:	public std::exception
		{
			public:
				const char* what(void) const throw();
		};

		class FileNotWorkingException
			:	public std::exception
		{
			public:
				const char* what(void) const throw();
		};

		void								setType(const std::string& type);
		const std::string&					getType(void) const;

		const std::string&					getName(void) const;
		const int&							getSignGrade(void) const;
		const int&							getExecGrade(void) const;
		const bool&							getSigned(void) const;

		void								beSigned(const Bureaucrat& b);

		void								executable(const Bureaucrat& b) const;
		virtual void						execute(const Bureaucrat& b) const = 0;

		Form(void);
		Form&								operator=(const Form& f);
		Form(const Form& f);
		Form(const std::string& name, const int& sign_grade, const int& exec_grade);
		virtual ~Form(void);
};

std::ostream&								operator<<(std::ostream& o, const Form& f);

#endif
