/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:04:40 by jseo              #+#    #+#             */
/*   Updated: 2021/10/10 21:26:17 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <string>

std::string						Brain::randomString(void)
{
	static std::string		characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	std::string				temp(I_LENGTH, '\0');
	std::string::iterator	iter = temp.begin();
	std::string::iterator	end = temp.end();

	while (iter != end)
		*iter++ = characters.at(static_cast<int>(Random::randr(0.0, 61.0)));
	return (temp);
}

void							Brain::setIdea(const int& i, const std::string& idea)
{
	_idea[i] = idea;
}

std::string						Brain::getIdea(const int& i) const
{
	return (_idea[i]);
}

Brain&							Brain::operator=(const Brain& b)
{
	if (this != &b)
		for (int i = 0 ; i < I_SIZE ; ++i)
			_idea[i] = b.getIdea(i);
	std::cout << " [ " << std::setw(W_SIZE) << B_NAME << " ] "
				<< "Assigned" << std::endl;
	return (*this);
}

Brain::Brain(void)
{
	for (int i = 0 ; i < I_SIZE ; ++i)
		_idea[i] = Brain::randomString();
	std::cout << " [ " << std::setw(W_SIZE) << B_NAME << " ] "
				<< "Default constructed" << std::endl;
}

Brain::Brain(const Brain& b)
{
	for (int i = 0 ; i < I_SIZE ; ++i)
		_idea[i] = b.getIdea(i);
	std::cout << " [ " << std::setw(W_SIZE) << B_NAME << " ] "
				<< "Copy constructed" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << " [ " << std::setw(W_SIZE) << B_NAME << " ] "
			<< "Destructed" << std::endl;
}

std::ostream&					operator<<(std::ostream& o, const Brain& b)
{
	for (int i = 0 ; i < I_SIZE ; ++i)
		std::cout << i + 1 << ".\t" << b.getIdea(i) << std::endl;
	return (o);
}
