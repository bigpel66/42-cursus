/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yield.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 19:58:24 by jseo              #+#    #+#             */
/*   Updated: 2021/06/15 19:58:42 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	yield(t_ps **ps)
{
	int	e;

	e = (*ps)->e;
	if (e <= 3)
		sort_3_asc(ps, e);
	else if (e <= 5)
		return (sort_5(ps, e, true));
	else if (e <= 100)
		jputstr("under 100\n", STDOUT_FILENO);
	else
		jputstr("others\n", STDOUT_FILENO);
	return (true);
}
