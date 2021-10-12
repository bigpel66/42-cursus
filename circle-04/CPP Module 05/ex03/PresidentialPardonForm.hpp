/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 01:45:39 by jseo              #+#    #+#             */
/*   Updated: 2021/10/12 16:32:49 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRESIDENTIAL_PARDON_FORM__
# define __PRESIDENTIAL_PARDON_FORM__

# include "Form.hpp"

# define P_NAME								"PresidentialPardonForm"
# define P_FORM								"presidential pardon"
# define P_SIGN								25
# define P_EXEC								5

class PresidentialPardonForm : public Form
{
	private:
		PresidentialPardonForm(void);

	public:
		void								execute(const Bureaucrat& b) const;

		PresidentialPardonForm&				operator=(const PresidentialPardonForm& p);
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& p);
		~PresidentialPardonForm(void);
};

#endif
