/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:57:53 by jseo              #+#    #+#             */
/*   Updated: 2021/04/22 13:46:29 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	chk_resolution(t_scene *rt)
{
	++(rt->cnt.r);
	if (rt->cnt.r == 1)
		return (TRUE);
	else
	{
		printf("Detail: Resolution is not unique\n");
		return (FALSE);
	}
}
