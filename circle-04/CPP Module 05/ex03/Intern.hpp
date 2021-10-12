/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:58:46 by jseo              #+#    #+#             */
/*   Updated: 2021/10/12 16:27:39 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_H__
# define __INTERN_H__

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		class NoMatchingTypeException
			:	public std::exception
		{
			public:
				const char* what(void) const throw();
		};

		Form*								makeForm(const std::string& type, const std::string& name);

		Intern(void);
		Intern&								operator=(const Intern& i);
		Intern(const Intern& i);
		~Intern(void);

};

#endif
