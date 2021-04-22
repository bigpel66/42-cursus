/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:57:22 by jseo              #+#    #+#             */
/*   Updated: 2021/04/22 13:46:23 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	chk_ambient(t_scene *rt)
{
	++(rt->cnt.a);
	if (rt->cnt.a == 1)
		return (TRUE);
	else
	{
		printf("Detail: Ambient is not unique\n");
		return (FALSE);
	}
}
