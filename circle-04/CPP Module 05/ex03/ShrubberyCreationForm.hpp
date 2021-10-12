/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 01:44:00 by jseo              #+#    #+#             */
/*   Updated: 2021/10/12 16:33:20 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUBBERY_CREATION_FORM__
# define __SHRUBBERY_CREATION_FORM__

# include "Form.hpp"

# define S_NAME								"ShrubberyCreationForm"
# define S_FORM								"shrubbery creation"
# define S_SIGN								145
# define S_EXEC								137

class ShrubberyCreationForm : public Form
{
	private:
		ShrubberyCreationForm(void);

	public:
		void								execute(const Bureaucrat& b) const;

		ShrubberyCreationForm&				operator=(const ShrubberyCreationForm& s);
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& s);
		~ShrubberyCreationForm(void);
};

#endif
