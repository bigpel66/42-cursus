/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 01:25:35 by jseo              #+#    #+#             */
/*   Updated: 2021/10/11 01:30:13 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

#include <iostream>

ICharacter::ICharacter(void)
{
	std::cout << "test a" << std::endl;
}

ICharacter::~ICharacter(void)
{
	std::cout << "test b" << std::endl;
}
