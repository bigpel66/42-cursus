/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:25:36 by jseo              #+#    #+#             */
/*   Updated: 2021/10/23 02:49:57 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONVERT_H__
# define __CONVERT_H__

# include <cmath>
# include <cstdlib>
# include <limits>
# include <iomanip>
# include <iostream>
# include <sstream>
# include <stdexcept>
# include <string>

# define C_ND								"Non displayable"
# define C_NP								"impossible"

class Convert
{
	private:
		bool								_e;
		const std::string					_input;
		const double						_value;

		Convert(void);

	public:
		char								toChar(void) const;
		int									toInt(void) const;
		float								toFloat(void) const;
		double								toDouble(void) const;

		bool								getError(void) const;
		const double&						getValue(void) const;
		const std::string&					getInput(void) const;

		Convert&							operator=(const Convert& c);
		Convert(const std::string& input);
		Convert(const Convert& c);
		~Convert(void);
};

std::ostream&								operator<<(std::ostream& o, const Convert& c);

#endif
