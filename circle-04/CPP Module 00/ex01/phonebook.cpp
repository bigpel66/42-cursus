/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:11:15 by jseo              #+#    #+#             */
/*   Updated: 2021/10/06 19:18:12 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void			Contact::set_field(int f_type, std::string& in, const std::string& phrase)
{
	const std::string	whitespace = " \t\n\v\r\f";

	in.clear();
	std::cout << phrase;
	if (!(std::getline(std::cin >> std::ws, in)) || std::cin.eof())
		exit(1);
	in.erase(in.find_last_not_of(whitespace) + 1);
	switch (f_type)
	{
		case F_F_NAME:
			_f_name = in;
			break ;
		case F_L_NAME:
			_l_name = in;
			break ;
		case F_ALIAS:
			_alias = in;
			break ;
		case F_PHONE:
			_phone = in;
			break ;
		case F_SECRET:
			_secret = in;
			break ;
	}
}

std::string		Contact::get_f_name(void) const
{
	return (_f_name);
}

std::string		Contact::get_l_name(void) const
{
	return (_l_name);
}

std::string		Contact::get_alias(void) const
{
	return (_alias);
}

std::string		Contact::get_phone(void) const
{
	return (_phone);
}

std::string		Contact::get_secret(void) const
{
	return (_secret);
}

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void			PhoneBook::_panel_header(void) const
{
	std::cout << std::endl
				<< std::setfill('=') << std::setw(42) << EOC << std::endl
				<< "|" << std::setfill(' ') << std::setw(35) << "Mini Phone Book |" << std::endl
				<< "|" << std::setfill(' ') << std::setw(35) << "...by jseo |" << std::endl
				<< std::setfill('=') << std::setw(42) << EOC << std::endl;
}

void			PhoneBook::panel_cmd(void) const
{
	std::cout << std::endl
				<< "Type the command to process [ "
				<< RED << "EXIT (exit)" << EOC << " | "
				<< YELLOW << "ADD (add)" << EOC << " | "
				<< BLUE << "SEARCH (search)" << EOC << " ]\n"
				<< "\t>>\t";
}

void			PhoneBook::cmd_input(void)
{
	std::size_t			size;
	const std::string	whitespace = " \t\n\v\r\f";

	if (!(std::getline(std::cin >> std::ws, _cmd)) || std::cin.eof())
		exit(1);
	_cmd.erase(_cmd.find_last_not_of(whitespace) + 1);
	size = _cmd.size();
	for (std::size_t i = 0 ; i < size ; ++i)
		_cmd[i] = std::toupper(_cmd[i]);
	std::cout << std::endl;
}

int				PhoneBook::cmd_type(void) const
{
	if (_cmd == _cmd_exit)
		return (CMD_EXIT);
	else if (_cmd == _cmd_add)
		return (CMD_ADD);
	else if (_cmd == _cmd_search)
		return (CMD_SEARCH);
	return (CMD_NO_MATCH);
}

std::string		PhoneBook::cmd_output(void) const
{
	return (_cmd);
}

void			PhoneBook::contact_add(void)
{
	std::string			temp;

	if (_o)
		std::cout << RED << "Contact will be OVERWRITTEN due to the FULLNESS!" << EOC << std::endl;
	std::cout << "Contact Index : [ "
				<< (_o ? RED : YELLOW) << _i + 1 << EOC
				<< " / "
				<< PB_SIZE
				<< " ]" << std::endl;
	_c[_i].set_field(F_F_NAME, temp, "1. First Name : ");
	_c[_i].set_field(F_L_NAME, temp, "2. Last Name : ");
	_c[_i].set_field(F_ALIAS, temp, "3. Nickname : ");
	_c[_i].set_field(F_PHONE, temp, "4. Phone Number : ");
	_c[_i].set_field(F_SECRET, temp, "5. Darkest Secret : ");
	if (!_o && _i == PB_SIZE - 1)
		_o = true;
	_i = (_i + 1) % PB_SIZE;
}

std::string		PhoneBook::_cut(std::string s) const
{
	if (s.size() > PADD_SIZE)
	{
		s[PADD_SIZE - 1] = '.';
		s.erase(PADD_SIZE);
	}
	return (s);
}

void			PhoneBook::_detail(void) const
{
	int					opt;

	while (true)
	{
		std::cout << std::endl << "Select the index to search (0 to close)\t>>\t";
		std::cin >> opt;
		if (std::cin.fail() || opt > PB_SIZE)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
			std::cout << RED << "Wrong Input" << EOC << std::endl << std::endl;
			continue;
		}
		break ;
	}
	if (!opt)
		return ;
	std::cout << std::endl
				<< GREEN << "1. First Name : " << EOC << _c[opt - 1].get_f_name() << std::endl
				<< GREEN << "2. Last Name : " << EOC <<_c[opt - 1].get_l_name() << std::endl
				<< GREEN << "3. Nickname : " << EOC << _c[opt - 1].get_alias() << std::endl
				<< GREEN << "4. Phone Number : " << EOC << _c[opt - 1].get_phone() << std::endl
				<< GREEN << "5. Darkest Secret : " << EOC << _c[opt - 1].get_secret() << std::endl << std::endl;

}

void			PhoneBook::contact_search(void) const
{
	int					size = _o ? PB_SIZE : _i;

	if (!size)
	{
		std::cout << RED << "Empty Phone Book" << EOC << std::endl;
		return ;
	}
	std::cout << std::setfill('=') << std::setw(51) << EOC << std::endl << "|"
				<< std::setfill(' ') << std::setw(PADD_SIZE) << "index" << "|"
				<< std::setfill(' ') << std::setw(PADD_SIZE) << "first name" << "|"
				<< std::setfill(' ') << std::setw(PADD_SIZE) << "last name" << "|"
				<< std::setfill(' ') << std::setw(PADD_SIZE) << "nickname" << "|" << std::endl
				<< std::setfill('=') << std::setw(51) << EOC << std::endl;
	for (int i = 0 ; i < size ; ++i)
	{
		std::cout << "|" << YELLOW << std::setfill(' ') << std::setw(PADD_SIZE) << i + 1 << EOC << "|"
					<< std::setfill(' ') << std::setw(PADD_SIZE) << _cut(_c[i].get_f_name()) << "|"
					<< std::setfill(' ') << std::setw(PADD_SIZE) << _cut(_c[i].get_l_name()) << "|"
					<< std::setfill(' ') << std::setw(PADD_SIZE) << _cut(_c[i].get_alias()) << "|" << std::endl
					<< std::setfill('=') << std::setw(51) << EOC << std::endl;
	}
	_detail();

}

PhoneBook::PhoneBook(void)
	: _cmd_exit("EXIT"), _cmd_add("ADD"), _cmd_search("SEARCH"), _i(0), _o(false)
{
	std::cout << YELLOW << "Opening Phone Book..." << EOC << std::endl;
	std::cout << GREEN << "Phone Book has been opened" << EOC << std::endl;
	_panel_header();
}

PhoneBook::~PhoneBook(void)
{
	std::cout << YELLOW << "Closing Phone Book..." << EOC << std::endl;
	std::cout << GREEN << "Phone Book has been closed" << EOC << std::endl;
}
