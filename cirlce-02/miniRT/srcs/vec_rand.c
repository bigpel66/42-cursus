/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rand.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:29:11 by jseo              #+#    #+#             */
/*   Updated: 2021/04/21 16:45:07 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	v_randr(double min, double max)
{
	t_vec3	t;

	v_init(&t, randr(min, max), randr(min, max), randr(min, max));
	return (t);
}

t_vec3	v_rand_in_unit_sphere(void)
{
	t_vec3	t;

	while (TRUE)
	{
		t = v_randr(-1.0, 1.0);
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
		v_init(&t, randr(-1.0, 1.0), randr(-1.0, 1.0), 0.0);
		if (v_size_squared(t) >= 1.0)
			continue ;
		return (t);
	}
}

t_vec3	v_rand_unit(void)
{
	return (v_unit(v_rand_in_unit_sphere()));
}
