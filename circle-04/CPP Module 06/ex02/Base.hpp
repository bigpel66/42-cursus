/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:05:59 by jseo              #+#    #+#             */
/*   Updated: 2021/10/13 17:09:10 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BASE_H__
# define __BASE_H__

# include "Random.hpp"
# include <exception>
# include <iostream>
# include <string>

class Base
{
	public:
		virtual ~Base(void) {};
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base*						generate(void);
void						identify(Base* p);
void						identify(Base& p);

#endif
