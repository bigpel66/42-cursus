/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:11:33 by jseo              #+#    #+#             */
/*   Updated: 2021/10/09 19:52:05 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAP_TRAP_H__
# define __CLAP_TRAP_H__

# include <string>
# include <iomanip>
# include <iostream>

# define RED						"\033[0;31m"
# define GREEN						"\033[0;32m"
# define YELLOW						"\033[1;33m"
# define EOC						"\033[0;0m"
# define W_SIZE						12

class ClapTrap
{
	private:
		static const std::string	_class_name;
		static const unsigned int	_class_hp;
		static const unsigned int	_class_ep;
		static const unsigned int	_class_ad;

	protected:
		std::string					_name;
		unsigned int				_hp;
		unsigned int				_ep;
		unsigned int				_ad;
		unsigned int				_max_hp;

	public:
		virtual void				attack(const std::string& target);
		void						takeDamage(unsigned int amount);
		void						beRepaired(unsigned int amount);

		void						setName(const std::string& name);
		void						setHP(unsigned int& hp);
		void						setEP(unsigned int& ep);
		void						setAD(unsigned int& ad);

		std::string					getName(void) const;
		unsigned int				getHP(void) const;
		unsigned int				getEP(void) const;
		unsigned int				getAD(void) const;

		static std::string			getClassName(void);
		static unsigned int			getClassHP(void);
		static unsigned int			getClassEP(void);
		static unsigned int			getClassAD(void);

		ClapTrap&					operator=(const ClapTrap& c);
		ClapTrap(void);
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& c);
		virtual ~ClapTrap(void);
};

#endif
