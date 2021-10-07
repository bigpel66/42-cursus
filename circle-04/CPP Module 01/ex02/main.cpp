/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:19:39 by jseo              #+#    #+#             */
/*   Updated: 2021/10/07 19:05:06 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	const std::string			str = std::string("HI THIS IS BRAIN");
	const std::string			*stringPTR = &str;
	const std::string			&stringREF = str;

	std::cout << "Address of the original string\t: " << &str << std::endl
				<< "Address of the string in PTR\t: " << stringPTR << std::endl
				<< "Address of the string in REF\t: " << &stringREF << std::endl
				<< std::endl;
	std::cout << "String content by PTR\t\t: " << *stringPTR << std::endl
				<< "String content by REF\t\t: " << stringREF << std::endl;
	return (0);
}
