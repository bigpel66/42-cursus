/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 15:06:53 by jseo              #+#    #+#             */
/*   Updated: 2021/12/24 22:50:01 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rbtree.h"

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
** print_node ()		- Print the Information of Node on the Screen
**
** return				- void
** node					- Specific Node
** level				- Depth of the Node for Padding
*/

void	print_node(t_node *node, int level)
{
	if (node == NULL)
	{
		padding('\t', level);
		jputendl("NIL", STDOUT_FILENO);
	}
	else
	{
		print_node(node->right, level + 1);
		padding('\t', level);
		if(get_color(node) == BLACK)
		{
			jputstr("(", STDOUT_FILENO);
			jputstr((char *)(node->key), STDOUT_FILENO);
			jputstr(") : ", STDOUT_FILENO);
			jputendl((char *)(node->value), STDOUT_FILENO);
		}
		else
		{
			jputstr((char *)(node->key), STDOUT_FILENO);
			jputstr(" : ", STDOUT_FILENO);
			jputendl((char *)(node->value), STDOUT_FILENO);
		}
		print_node(node->left, level + 1);
	}
}

/*
** print_tree			- Print the Total Nodes of RB Tree
**
** return				- void
** tree					- RB Tree
*/

void	print_tree(t_rb* tree)
{
	print_node(tree->root, 0);
	jputendl("-------------------------------------------", STDOUT_FILENO);
}
