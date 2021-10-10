/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:50:04 by jseo              #+#    #+#             */
/*   Updated: 2021/10/10 20:14:44 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_H__
# define __BRAIN_H__

# include "Random.hpp"
# include <iomanip>
# include <iostream>
# include <string>

# define W_SIZE					12
# define B_NAME					"Brain"
# define I_SIZE					100
# define I_LENGTH				10

class Brain
{
	private:
		std::string				_idea[I_SIZE];

	public:
		static std::string		randomString(void);
		void					setIdea(const int& i, const std::string& idea);
		std::string				getIdea(const int& i) const;

		Brain&					operator=(const Brain& b);
		Brain(void);
		Brain(const Brain& b);
		~Brain();
};

std::ostream&					operator<<(std::ostream& o, const  Brain& b);

#endif
