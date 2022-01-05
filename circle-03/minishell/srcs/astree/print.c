/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:12:43 by jseo              #+#    #+#             */
/*   Updated: 2022/01/05 09:14:00 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astree.h"

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
