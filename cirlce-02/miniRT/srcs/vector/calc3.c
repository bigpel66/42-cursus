/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:28:54 by jseo              #+#    #+#             */
/*   Updated: 2021/05/07 17:38:03 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	reflect(t_vec3 v, t_vec3 n)
{
	return (sub(v, scale(scale(n, dot(v, n)), 2.0)));
}

t_vec3	refract(t_vec3 uv, t_vec3 n, double etai_over_etat)
{
	double	cos_theta;
	t_vec3	ray_out_perp;
	t_vec3	ray_out_paral;

	cos_theta = fmin(dot(flip(uv), n), 1.0);
	ray_out_perp = scale(add(uv, scale(n, cos_theta)), etai_over_etat);
	ray_out_paral = scale(n, -sqrt(fabs(1.0 - len_pow(ray_out_perp))));
	return (add(ray_out_perp, ray_out_paral));
}
