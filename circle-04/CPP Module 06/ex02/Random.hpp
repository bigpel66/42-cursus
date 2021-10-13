/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Random.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:54:56 by jseo              #+#    #+#             */
/*   Updated: 2021/10/10 19:58:18 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RANDOM_H__
# define __RANDOM_H__

class Random
{
	private:
		static int				seed;

		Random(void);
		~Random(void);

	public:
		static double			randv(void);
		static double			randr(double min, double max);
};

#endif
