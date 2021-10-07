/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:19:39 by jseo              #+#    #+#             */
/*   Updated: 2021/10/07 16:29:48 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string			str = std::string("HI THIS IS BRAIN");
	std::string			*stringPTR = &str;
	std::string			&stringREF = str;

	std::cout << "Address of the original string\t: " << &str << std::endl
				<< "Address of the string in PTR\t: " << stringPTR << std::endl
				<< "Address of the string in REF\t: " << &stringREF << std::endl
				<< std::endl;
	std::cout << "String content by PTR\t\t: " << *stringPTR << std::endl
				<< "String content by REF\t\t: " << stringREF << std::endl;
	return (0);
}
