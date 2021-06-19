/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 22:42:17 by jseo              #+#    #+#             */
/*   Updated: 2021/06/17 15:54:37 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inst_ra(t_ps **ps, char *cmd)
{
	t_list	*tmp;

	if (jlstempty((*ps)->ah))
		return ;
	tmp = (*ps)->ah;
	(*ps)->ah = tmp->n;
	(*ps)->at = tmp;
	jputstr(cmd, STDOUT_FILENO);
	if (*cmd)
		jputchar('\n', STDOUT_FILENO);
}

void	inst_rb(t_ps **ps, char *cmd)
{
	t_list	*tmp;

	if (jlstempty((*ps)->bh))
		return ;
	tmp = (*ps)->bh;
	(*ps)->bh = tmp->n;
	(*ps)->bt = tmp;
	jputstr(cmd, STDOUT_FILENO);
	if (*cmd)
		jputchar('\n', STDOUT_FILENO);
}

void	inst_rr(t_ps **ps, char *cmd)
{
	inst_ra(ps, "");
	inst_rb(ps, "");
	jputstr(cmd, STDOUT_FILENO);
	jputchar('\n', STDOUT_FILENO);
}
