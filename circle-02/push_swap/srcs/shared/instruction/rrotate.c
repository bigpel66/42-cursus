/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 22:42:24 by jseo              #+#    #+#             */
/*   Updated: 2021/06/17 15:54:51 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	inst_rra(t_ps **ps, char *cmd)
{
	t_list	*tmp;

	if (jlstempty((*ps)->at))
		return ;
	tmp = (*ps)->at;
	(*ps)->ah = tmp;
	(*ps)->at = tmp->p;
	jputstr(cmd, STDOUT_FILENO);
	if (*cmd)
		jputchar('\n', STDOUT_FILENO);
}

void	inst_rrb(t_ps **ps, char *cmd)
{
	t_list	*tmp;

	if (jlstempty((*ps)->bt))
		return ;
	tmp = (*ps)->bt;
	(*ps)->bh = tmp;
	(*ps)->bt = tmp->p;
	jputstr(cmd, STDOUT_FILENO);
	if (*cmd)
		jputchar('\n', STDOUT_FILENO);
}

void	inst_rrr(t_ps **ps, char *cmd)
{
	inst_rra(ps, "");
	inst_rrb(ps, "");
	jputstr(cmd, STDOUT_FILENO);
	jputchar('\n', STDOUT_FILENO);
}
