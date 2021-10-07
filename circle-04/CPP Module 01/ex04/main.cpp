/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:42:06 by jseo              #+#    #+#             */
/*   Updated: 2021/10/07 18:55:09 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int main(int argc, char **argv)
{
	if (argc !=  4)
		std::cout << "Command Not Formatted Well" << std::endl
			<< "./replace [ File Name ] [ String1 for SRC ] [ String2 for DST ]" << std::endl;
	else
		Replace::process(argv[1], argv[2], argv[3]);
	return (0);
}
