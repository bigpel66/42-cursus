/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:20:08 by jseo              #+#    #+#             */
/*   Updated: 2021/10/07 21:46:34 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(void)
{
	Karen		k;

	k.complain("debug");
	k.complain("bacon");
	k.complain("burger");
	k.complain("DEBUG");
	k.complain("INFO");
	k.complain("WARNING");
	k.complain("ERROR");
	return (0);
}
