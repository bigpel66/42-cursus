/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 01:44:48 by jseo              #+#    #+#             */
/*   Updated: 2021/10/12 03:51:10 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ROBOTOMY_REQUEST_FORM__
# define __ROBOTOMY_REQUEST_FORM__

# include "Form.hpp"

# define R_NAME								"RotobomyRequestForm"
# define R_SIGN								72
# define R_EXEC								45

class RobotomyRequestForm : public Form
{
	private:
		RobotomyRequestForm(void);

	public:
		void								execute(const Bureaucrat& b) const;

		RobotomyRequestForm&				operator=(const RobotomyRequestForm& r);
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& r);
		~RobotomyRequestForm(void);
};

#endif
