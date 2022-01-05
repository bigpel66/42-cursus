/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:51:45 by jseo              #+#    #+#             */
/*   Updated: 2022/01/05 12:06:58 by jseo             ###   ########.fr       */
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
** as_mixin ()			- Check Syntax Mixed or Not
**
** return				- True or False
** syntax				- AS Tree
** lchild				- Left Child
** rchild				- Right Child
*/

static inline bool	as_mixin(t_as *syntax)
{
	t_as	*lchild;
	t_as	*rchild;

	lchild = syntax->left;
	rchild = syntax->right;
	if (!syntax->root && syntax->type == PIPE)
		if (lchild != NULL && lchild->type == RDR)
			return (true);
	if (syntax->type == PIPE)
	{
		if (lchild != NULL && lchild->heredoc)
			return (true);
		if (rchild != NULL && rchild->heredoc)
			return (true);
	}
	return (false);
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
	if (as_mixin(syntax))
		return (false);
	if (!as_check(syntax->right) || !as_check(syntax->left))
		return (false);
	return (true);
}
