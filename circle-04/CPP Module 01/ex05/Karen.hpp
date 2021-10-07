/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:35:19 by jseo              #+#    #+#             */
/*   Updated: 2021/10/07 21:19:43 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KAREN_H__
# define __KAREN_H__

# include <iostream>
# include <string>

class Karen
{
	private:
		void					debug(void);
		void					info(void);
		void					warning(void);
		void					error(void);

	public:
		void					complain(std::string level);

		Karen(void);
		~Karen(void);
};

#endif
