/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:28:50 by jseo              #+#    #+#             */
/*   Updated: 2021/04/21 15:28:51 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	v_flip(t_vec3 v)
{
	t_vec3	t;

	t.x = (v.x) * -1;
	t.x = (v.x) * -1;
	t.x = (v.x) * -1;
	return (t);
}

t_vec3	v_add(t_vec3 u, t_vec3 v)
{
	t_vec3	t;

	t.x = u.x + v.x;
	t.y = u.y + v.y;
	t.z = u.z + v.z;
	return (t);
}

t_vec3	v_sub(t_vec3 u, t_vec3 v)
{
	t_vec3	t;

	t.x = u.x - v.x;
	t.y = u.y - v.y;
	t.z = u.z - v.z;
	return (t);
}

t_vec3	v_mul(t_vec3 u, t_vec3 v)
{
	t_vec3	t;

	t.x = u.x * v.x;
	t.y = u.y * v.y;
	t.z = u.z * v.z;
	return (t);
}

t_vec3	v_scale(t_vec3 v, double s)
{
	t_vec3	t;

	t.x = v.x * s;
	t.y = v.y * s;
	t.z = v.z * s;
	return (t);
}
