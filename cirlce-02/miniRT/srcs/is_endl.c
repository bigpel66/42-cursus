/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_endl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:16:42 by jseo              #+#    #+#             */
/*   Updated: 2021/04/19 15:16:44 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	is_endl(const char *s)
{
	if (!s)
		return (FALSE);
	while (*s && is_blank((*s)))
		++s;
	if (!*s)
		return (TRUE);
	return (FALSE);
}
