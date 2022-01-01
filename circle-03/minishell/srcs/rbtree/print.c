/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 15:06:53 by jseo              #+#    #+#             */
/*   Updated: 2022/01/01 12:38:33 by jseo             ###   ########.fr       */
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
** rb_node ()			- Print the Information of Node on the Screen
**
** return				- void
** node					- Specific Node
** level				- Depth of the Node for Padding
*/

void	rb_node(t_node *node, int level)
{
	if (node == NULL)
	{
		padding('\t', level);
		jputendl("NIL", STDOUT_FILENO);
	}
	else
	{
		rb_node(node->right, level + 1);
		padding('\t', level);
		if (get_color(node) == BLACK)
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
		rb_node(node->left, level + 1);
	}
}

/*
** rb_print ()			- Print the Total Nodes of RB Tree
**
** return				- void
** tree					- RB Tree
*/

void	rb_print(t_rb *tree)
{
	rb_node(tree->root, 0);
	jputendl("-------------------------------------------", STDOUT_FILENO);
}

/*
** rb_order ()			- Print the Total Nodes in Ascending Order
**
** return				- void
** node					- Specific Node
*/

void	rb_order(t_node *node)
{
	if (node == NULL)
		return ;
	rb_order(node->left);
	rb_order(node->right);
	if (!jstrncmp((char *)(node->key), "#", BUFFER_SIZE) ||
		!jstrncmp((char *)(node->key), "*", BUFFER_SIZE) ||
		!jstrncmp((char *)(node->key), "?", BUFFER_SIZE))
		return ;
	if (!*((char *)(node->value)))
		return ;
	jputstr((char *)(node->key), STDOUT_FILENO);
	jputstr("=", STDOUT_FILENO);
	jputendl((char *)(node->value), STDOUT_FILENO);
}
