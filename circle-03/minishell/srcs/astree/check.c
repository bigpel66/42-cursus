/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:51:45 by jseo              #+#    #+#             */
/*   Updated: 2022/01/05 09:20:50 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astree.h"

/*
** as_assert ()			- Assert Whether Condition True or False
**
** return				- void
** condition			- Condition to Check
** context				- Context Information in Runtime
*/

void	as_assert(bool condition, char *context)
{
	if (condition)
		return ;
	jputendl(context, STDERR_FILENO);
	exit(GENERAL);
}

/*
** as_check ()			- Check AS Tree Completed
**
** return				- Whether the AS Tree Well Structured or Not
** syntax				- AS Tree
*/

bool	as_check(t_as *syntax)
{
	if (syntax == NULL)
		return (true);
	if (syntax->type == PIPE || syntax->type == RDR)
		if (syntax->left == NULL)
			return (false);
	if (!syntax->root && syntax->type == PIPE && syntax->left->type == RDR)
		return (false);
	if (!as_check(syntax->right) || !as_check(syntax->left))
		return (false);
	return (true);
}
