/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:41:45 by jseo              #+#    #+#             */
/*   Updated: 2021/04/18 16:41:46 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	get_index(const char *s, int c)
{
	t_bool	i;

	i = FALSE;
	while (s[i])
		if (s[i++] == (char)c)
			return (i);
	return (FALSE);
}
