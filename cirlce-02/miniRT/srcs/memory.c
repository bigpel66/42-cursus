/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:30:18 by jseo              #+#    #+#             */
/*   Updated: 2021/04/21 20:01:15 by jseo             ###   ########.fr       */
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

void	free_ptr(void **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}

void	free_scene(t_scene *rt)
{
	if (rt->c)
		free_ptr((void **)(&(rt->c)));
	if (rt->l)
		free_ptr((void **)(&(rt->l)));
	if (rt->sp)
		free_ptr((void **)(&(rt->sp)));
	if (rt->pl)
		free_ptr((void **)(&(rt->pl)));
	if (rt->sq)
		free_ptr((void **)(&(rt->sq)));
	if (rt->cy)
		free_ptr((void **)(&(rt->cy)));
	if (rt->tr)
		free_ptr((void **)(&(rt->tr)));
}
