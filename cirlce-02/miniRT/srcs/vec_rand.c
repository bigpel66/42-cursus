/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rand.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:29:11 by jseo              #+#    #+#             */
/*   Updated: 2021/04/21 15:29:13 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	v_rand_range(double min, double max)
{
	t_vec3	t;

	t.x = rand_double_range(min, max);
	t.y = rand_double_range(min, max);
	t.z = rand_double_range(min, max);
	return (t);
}

t_vec3	v_rand_in_unit_sphere(void)
{
	t_vec3	t;

	while (TRUE)
	{
		t = v_rand_range(-1.0, 1.0);
		if (v_size_squared(t) >= 1.0)
			continue ;
		return (t);
	}
}

t_vec3	v_rand_in_unit_hemisphere(t_vec3 n)
{
	t_vec3	t;

	t = v_rand_in_unit_sphere();
	if (v_dot(t, n) > 0.0)
		return (t);
	return (v_flip(t));
}

t_vec3	v_rand_in_unit_disk(void)
{
	t_vec3	t;

	while (TRUE)
	{
		t.x = rand_double_range(-1.0, 1.0);
		t.y = rand_double_range(-1.0, 1.0);
		t.z = 0.0;
		if (v_size_squared(t) >= 1.0)
			continue ;
		return (t);
	}
}

t_vec3	v_rand_unit(void)
{
	return (v_unit(v_rand_in_unit_sphere()));
}
