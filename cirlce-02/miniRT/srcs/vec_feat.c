/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_feat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:28:54 by jseo              #+#    #+#             */
/*   Updated: 2021/04/21 15:28:56 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	v_unit(t_vec3 v)
{
	return (v_scale(v, (1.0 / v_size(v))));
}

t_vec3	v_reflect(t_vec3 v, t_vec3 n)
{
	return (v_sub(v, v_scale(v_scale(n, v_dot(v, n)), 2.0)));
}

t_vec3	v_refract(t_vec3 uv, t_vec3 n, double etai_over_etat)
{
	double	cos_theta;
	t_vec3	ray_out_perp;
	t_vec3	ray_out_parallel;

	cos_theta = fmin(v_dot(v_flip(uv), n), 1.0);
	ray_out_perp = v_scale(v_add(uv, v_scale(n, cos_theta)), etai_over_etat);
	ray_out_parallel = v_scale(n, -sqrt(fabs(1.0 - v_size_squared(ray_out_perp))));
	return (v_add(ray_out_perp, ray_out_parallel));
}
