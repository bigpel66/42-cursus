/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:22:17 by jseo              #+#    #+#             */
/*   Updated: 2021/10/06 14:32:40 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1 ; i < argc ; ++i)
			for (int j = 0 ; argv[i][j] ; ++j)
				std::cout << static_cast<char>(std::toupper(argv[i][j]));
		std::cout << std::endl;
	}
	return (0);
}
