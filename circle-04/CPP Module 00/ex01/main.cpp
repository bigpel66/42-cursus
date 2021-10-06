/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:37:37 by jseo              #+#    #+#             */
/*   Updated: 2021/10/06 17:30:12 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(void)
{
	phonebook	pb;

	while (true)
	{
		pb.panel_cmd();
		pb.cmd_input();
		switch (pb.cmd_type())
		{
			case CMD_EXIT:
				return (0);
			case CMD_ADD:
				std::cout << YELLOW << "Adding Contact to Phone Book..." << EOC << std::endl;
				pb.contact_add();
				break ;
			case CMD_SEARCH:
				std::cout << BLUE << "Searching Contact to Phone Book..." << EOC << std::endl;
				pb.contact_search();
				break ;
			default:
				std::cout << RED << "Wrong Command : " << pb.cmd_output() << EOC << std::endl;
				continue ;
		}
	}
}
