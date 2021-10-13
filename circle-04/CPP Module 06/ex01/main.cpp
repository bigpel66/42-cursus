/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:48:33 by jseo              #+#    #+#             */
/*   Updated: 2021/10/13 18:19:29 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main(void)
{
	Data			d1;
	Data			d2("Macbook Pro 16''", 2141, 2799.0, 2000.0);
	uintptr_t		p1 = serialize(&d1);
	uintptr_t		p2 = serialize(&d2);

	std::cout << &d1 << std::endl;
	std::cout << d1;
	print(p1);
	std::cout << &d2 << std::endl;
	std::cout << d2;
	print(p2);
	return (0);
}
