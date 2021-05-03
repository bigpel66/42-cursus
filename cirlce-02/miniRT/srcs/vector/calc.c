/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:28:50 by jseo              #+#    #+#             */
/*   Updated: 2021/04/22 17:07:27 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	flip(t_vec3 v)
{
	return (v_init((v.x * -1), (v.y * -1), (v.z * -1)));
}

t_vec3	add(t_vec3 u, t_vec3 v)
{
	return (v_init((u.x + v.x), (u.y + v.y), (u.z + v.z)));
}

t_vec3	sub(t_vec3 u, t_vec3 v)
{
	return (v_init((u.x - v.x), (u.y - v.y), (u.z - v.z)));
}

t_vec3	scale(t_vec3 v, double s)
{
	return (v_init((v.x * s), (v.y * s), (v.z * s)));
}
