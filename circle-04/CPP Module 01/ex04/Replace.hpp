/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:55:24 by jseo              #+#    #+#             */
/*   Updated: 2021/10/07 20:11:42 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __REPLACE_H__
# define __REPLACE_H__

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>

class Replace
{
	private:
		Replace(void);
		~Replace(void);

		static void			_transform(std::string& str, const std::string& s1, const std::string& s2);

	public:
		static void			process(const std::string& txt, const std::string& s1, const std::string& s2);
};

#endif
