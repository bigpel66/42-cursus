/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:36:02 by jseo              #+#    #+#             */
/*   Updated: 2021/10/13 18:35:32 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DATA_H__
# define __DATA_H__

# include <cstdint>
# include <string>
# include <iostream>

class Data
{
	private:
		std::string						_model;
		int								_serial;
		double							_price;
		float							_weight;


	public:
		const std::string&				getModel(void) const;
		const int&						getSerial(void) const;
		const double&					getPrice(void) const;
		const float&					getWeight(void) const;

		Data&							operator=(const Data& d);
		Data(void);
		Data(const std::string& model, int serial, double price, float weight);
		Data(const Data& d);
		~Data(void);
};

uintptr_t								serialize(Data* ptr);
Data*									deserialize(uintptr_t raw);
std::ostream&							operator<<(std::ostream& o, const Data& ptr);
void									print(uintptr_t raw);

#endif
