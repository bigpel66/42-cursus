/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termination.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 16:45:33 by jseo              #+#    #+#             */
/*   Updated: 2021/06/11 16:48:01 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_ps(t_ps **ps)
{
	if (!*ps)
		return ;
	jlstclear(&((*ps)->ah));
	jlstclear(&((*ps)->bh));
	set_delete(&((*ps)->s));
	map_delete(&((*ps)->m));
	jfree((void **)(ps));
}

void		exit_invalid(t_ps **ps)
{
	free_ps(ps);
	jputstr("Error\n", STDERR_FILENO);
	exit(INVALID);
}

void		exit_valid(t_ps **ps)
{
	free_ps(ps);
	exit(VALID);
}
