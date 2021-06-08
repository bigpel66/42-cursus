/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:28:59 by jseo              #+#    #+#             */
/*   Updated: 2021/05/07 17:38:09 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	near_zero(t_vec3 v)
{
	double	e;

	e = 1e-8;
	return ((fabs(v.x) < e) && (fabs(v.y) < e) && (fabs(v.z) < e));
}

t_vec3	cross(t_vec3 u, t_vec3 v)
{
	t_vec3	t;

	t.x = u.y * v.z - u.z * v.y;
	t.y = u.z * v.x - u.x * v.z;
	t.z = u.x * v.y - u.y * v.x;
	return (t);
}

double	dot(t_vec3 u, t_vec3 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

double	len_pow(t_vec3 v)
{
	return ((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

double	len_sqrt(t_vec3 v)
{
	return (sqrt(len_pow(v)));
}
