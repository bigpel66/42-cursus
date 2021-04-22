/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_vec3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 22:20:09 by jseo              #+#    #+#             */
/*   Updated: 2021/04/18 23:16:02 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	is_blank(int c)
{
	return (c == ' ' || c == '\v' || c == '\t');
}

t_bool	is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

t_bool	is_endl(const char *s)
{
	if (!s)
		return (FALSE);
	while (*s && is_blank((*s)))
		++s;
	if (!*s)
		return (TRUE);
	return (FALSE);
}

t_bool	valid_vec3(t_vec3 v)
{
	return ((v.x >= 0.0 && v.x <= 1.0)
		&& (v.y >= 0.0 && v.y <= 1.0)
		&& (v.z >= 0.0 && v.z <= 1.0));
}

t_bool	valid_color(t_color c)
{
	return ((c.r >= 0.0 && c.r <= 255.0)
			&& (c.g >= 0.0 && c.g <= 255.0)
			&& (c.b >= 0.0 && c.b <= 255.0));
}
