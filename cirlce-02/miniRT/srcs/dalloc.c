/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dalloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:28:58 by jseo              #+#    #+#             */
/*   Updated: 2021/04/17 16:29:00 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	dalloc(void **ptr, size_t cnt, size_t n)
{
	*ptr = (void *)malloc(cnt * n);
	if (!*ptr)
		return (FALSE);
	ft_memset(*ptr, 0, cnt * n);
	return (TRUE);
}
