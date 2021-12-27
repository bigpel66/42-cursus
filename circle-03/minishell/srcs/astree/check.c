/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:51:45 by jseo              #+#    #+#             */
/*   Updated: 2021/12/28 03:11:50 by jseo             ###   ########.fr       */
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
	if (!as_check(syntax->right) || !as_check(syntax->left))
		return (false);
	return (true);
}

/*
** padding ()			- Print Padding on the Screen
**
** return				- void
** c					- Padding Character
** n					- Iterating Count
*/

static inline void	padding(char c, int n)
{
	int		i;

	i = -1;
	while (++i < n)
	{
		jputchar(c, STDOUT_FILENO);
		jputchar(c, STDOUT_FILENO);
	}
}

/*
** as_syntax ()			- Print the Information of Syntax Node on the Screen
**
** return				- void
** syntax				- Specific Syntax Node
** level				- Depth of the Syntax Node for Padding
*/

void	as_syntax(t_as *syntax, int level)
{
	if (syntax == NULL)
	{
		padding('\t', level);
		jputendl("NIL", STDOUT_FILENO);
	}
	else
	{
		as_syntax(syntax->right, level + 1);
		padding('\t', level);
		jputendl(syntax->token, STDOUT_FILENO);
		as_syntax(syntax->left, level + 1);
	}
}

/*
** as_print ()			- Print the Total Syntax Nodes of AS Tree
**
** return				- void
** syntax				- AS Tree
*/

void	as_print(t_as *syntax)
{
	as_syntax(syntax, 0);
	jputendl("-------------------------------------------", STDOUT_FILENO);
}
