/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:57:53 by jseo              #+#    #+#             */
/*   Updated: 2021/10/07 22:08:40 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(int argc, char **argv)
{
	Karen		k;

	if (argc != 2)
		std::cout << "Command Not Formatted Well" << std::endl
					<< "./karenFilter [ Level ]" << std::endl;
	else
		k.complain(argv[1]);
	return (0);
}
