/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:28:50 by jseo              #+#    #+#             */
/*   Updated: 2021/04/21 16:45:19 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	v_flip(t_vec3 v)
{
	t_vec3	t;

	v_init(&t, (v.x * -1), (v.y * -1), (v.z * -1));
	return (t);
}

t_vec3	v_add(t_vec3 u, t_vec3 v)
{
	t_vec3	t;

	v_init(&t, (u.x + v.x), (u.y + v.y), (u.z + v.z));
	return (t);
}

t_vec3	v_sub(t_vec3 u, t_vec3 v)
{
	t_vec3	t;

	v_init(&t, (u.x - v.x), (u.y - v.y), (u.z - v.z));
	return (t);
}

t_vec3	v_mul(t_vec3 u, t_vec3 v)
{
	t_vec3	t;

	v_init(&t, (u.x * v.x), (u.y * v.y), (u.z * v.z));
	return (t);
}

t_vec3	v_scale(t_vec3 v, double s)
{
	t_vec3	t;

	v_init(&t, (v.x * s), (v.y * s), (v.z * s));
	return (t);
}
