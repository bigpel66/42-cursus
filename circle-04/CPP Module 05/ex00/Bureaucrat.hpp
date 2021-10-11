/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:52:41 by jseo              #+#    #+#             */
/*   Updated: 2021/10/11 17:55:56 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_H__
# define __BUREAUCRAT_H__

# include <string>

class Bureaucrat
{
	private:
		const std::string					_name;
		int									_grade;

	public:

		Bureaucrat&							operator=(const Bureaucrat& b);
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat& b);
		~Bureaucrat(void);
};

#endif
