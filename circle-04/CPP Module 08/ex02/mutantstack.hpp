/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:49:33 by jseo              #+#    #+#             */
/*   Updated: 2021/10/15 15:06:00 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANT_STACK_H__
# define __MUTANT_STACK_H__

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		using iterator = typename std::stack<T>::container_type::iterator;
		using const_iterator = typename std::stack<T>::container_type::const_iterator;
		using reverse_iterator = typename std::stack<T>::container_type::reverse_iterator;
		using const_reverse_iterator = typename std::stack<T>::container_type::const_reverse_iterator;

		iterator							begin(void)
		{
			return (this->c.begin());
		}

		iterator							end(void)
		{
			return (this->c.end());
		}

		const_iterator						cbegin(void) const
		{
			return (this->c.cbegin());
		}

		const_iterator						cend(void) const
		{
			return (this->c.cend());
		}

		reverse_iterator					rbegin(void)
		{
			return (this->c.rbegin());
		}

		reverse_iterator					rend(void)
		{
			return (this->c.rend());
		}

		const_reverse_iterator				crbegin(void) const
		{
			return (this->c.crbegin());
		}

		const_reverse_iterator				crend(void) const
		{
			return (this->c.crend());
		}

		MutantStack&						operator=(const MutantStack& m) = default;
		MutantStack(void) = default;
		MutantStack(const MutantStack& m) = default;
		MutantStack(MutantStack&& m) = default;
		~MutantStack(void) = default;
};

#endif
