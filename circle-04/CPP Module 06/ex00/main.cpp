/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:22:04 by jseo              #+#    #+#             */
/*   Updated: 2021/10/13 18:31:32 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Command Not Formatted Well" << std::endl
					<< "./convert [ Convert Input ]" << std::endl;
	else
		std::cout << Convert(argv[1]);
	return (0);
}
