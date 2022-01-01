/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 13:53:24 by jseo              #+#    #+#             */
/*   Updated: 2022/01/01 12:38:34 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rbtree.h"

/*
** case_2 ()			- Insert Case 2
**
** return				- void
** tree					- RB Tree
** node					- A Node to Insert
** parent				- Parent of the Node to Insert
** grandparent			- Grandparent of the Node to Insert
** uncle				- Uncle of the Node to Insert
*/

static inline void	case_2(t_rb *tree, t_node **node, \
							t_node **parent, t_node **grandparent)
{
	t_node	*uncle;

	uncle = (*grandparent)->left;
	if (uncle && get_color(uncle) == RED)
	{
		set_color(*grandparent, RED);
		set_color(*parent, BLACK);
		set_color(uncle, BLACK);
		*node = *grandparent;
	}
	else
	{
		if (*node == (*parent)->left)
		{
			right_rotate(tree, *parent);
			*node = *parent;
			*parent = get_parent(*parent);
		}
		set_color(*parent, BLACK);
		set_color(*grandparent, RED);
		left_rotate(tree, *grandparent);
	}
}

/*
** case_1 ()			- Insert Case 1
**
** return				- void
** tree					- RB Tree
** node					- A Node to Insert
** parent				- Parent of the Node to Insert
** grandparent			- Grandparent of the Node to Insert
** uncle				- Uncle of the Node to Insert
*/

static inline void	case_1(t_rb *tree, t_node **node, \
							t_node **parent, t_node **grandparent)
{
	t_node	*uncle;

	uncle = (*grandparent)->right;
	if (uncle && get_color(uncle) == RED)
	{
		set_color(*grandparent, RED);
		set_color(*parent, BLACK);
		set_color(uncle, BLACK);
		*node = *grandparent;
	}
	else
	{
		if (*node == (*parent)->right)
		{
			left_rotate(tree, *parent);
			*node = *parent;
			*parent = get_parent(*parent);
		}
		set_color(*parent, BLACK);
		set_color(*grandparent, RED);
		right_rotate(tree, *grandparent);
	}
}

/*
** insert_internal ()	- Insert Logic of RB Tree
**
** return				- void
** tree					- RB Tree
** node					- A Node to Insert
** parent				- Parent of the Node to Insert
** grandparent			- Grandparent of the Node to Insert
*/

void	insert_internal(t_rb *tree, t_node *node, t_node *parent)
{
	t_node	*grandparent;

	while (parent != NULL && get_color(parent) == RED)
	{
		grandparent = get_parent(parent);
		if (parent == grandparent->left)
			case_1(tree, &node, &parent, &grandparent);
		else
			case_2(tree, &node, &parent, &grandparent);
		parent = get_parent(node);
	}
	set_color(tree->root, BLACK);
}
