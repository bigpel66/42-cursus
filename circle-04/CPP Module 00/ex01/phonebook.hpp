/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:06:24 by jseo              #+#    #+#             */
/*   Updated: 2021/10/06 19:18:11 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOK_H__
# define __PHONEBOOK_H__

# include <limits>
# include <iomanip>
# include <iostream>
# include <string>

# define CMD_NO_MATCH				-1
# define CMD_EXIT					0
# define CMD_ADD					1
# define CMD_SEARCH					2

# define F_F_NAME					0
# define F_L_NAME					1
# define F_ALIAS					2
# define F_PHONE					3
# define F_SECRET					4

# define PB_SIZE					8
# define PADD_SIZE					10

# define RED						"\033[0;31m"
# define YELLOW						"\033[1;33m"
# define GREEN						"\033[0;32m"
# define BLUE						"\033[0;34m"
# define EOC						"\033[0;0m"

class Contact
{
	private:
		std::string					_f_name;
		std::string					_l_name;
		std::string					_alias;
		std::string					_phone;
		std::string					_secret;

	public:
		void						set_field(int f_type, std::string& in, const std::string& phrase);
		std::string					get_f_name(void) const;
		std::string					get_l_name(void) const;
		std::string					get_alias(void) const;
		std::string					get_phone(void) const;
		std::string					get_secret(void) const;

		Contact(void);
		~Contact(void);
};

class PhoneBook
{
	private:
		const std::string			_cmd_exit;
		const std::string			_cmd_add;
		const std::string			_cmd_search;
		std::string					_cmd;
		Contact						_c[PB_SIZE];
		int							_i;
		bool						_o;

		void						_panel_header(void) const;
		std::string					_cut(std::string s) const;
		void						_detail(void) const;

	public:
		void						panel_cmd(void) const;
		void						cmd_input(void);
		int							cmd_type(void) const;
		std::string					cmd_output(void) const;
		void						contact_add(void);
		void						contact_search(void) const;

		PhoneBook(void);
		~PhoneBook(void);
};

#endif
