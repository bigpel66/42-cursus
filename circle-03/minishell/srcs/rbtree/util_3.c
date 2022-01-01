/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 22:53:49 by jseo              #+#    #+#             */
/*   Updated: 2022/01/01 12:38:28 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rbtree.h"

/*
** prev_element ()		- Getting the Previous Node from the Input Node
**
** return				- Previous Node
** node					- Specific Node
** parent				- Parent Node to Find the Previous Node in Iterating
*/

t_node	*prev_element(t_node *node)
{
	t_node	*parent;

	rb_assert(node != NULL, \
		RASSERT "(node != NULL), " PREV_ELEMENT RUTIL_3_FILE "line 27.");
	if (node->left != NULL)
		return (get_max(node->left));
	parent = get_parent(node);
	while (parent != NULL && parent->left == node)
	{
		node = parent;
		parent = get_parent(node);
	}
	return (parent);
}

/*
** next_element ()		- Getting the Next Node from the Input Node
**
** return				- Next Node
** node					- Specific Node
** parent				- Parent Node to Find the Next Node in Iterating
*/

t_node	*next_element(t_node *node)
{
	t_node	*parent;

	rb_assert(node != NULL, \
		RASSERT "(node != NULL), " NEXT_ELEMENT RUTIL_3_FILE "line 52.");
	if (node->right != NULL)
		return (get_min(node->right));
	parent = get_parent(node);
	while (parent != NULL && parent->right == node)
	{
		node = parent;
		parent = get_parent(node);
	}
	return (parent);
}

/*
** left_rotate ()		- Rotate the Tree to the Left Direction
**
** return				- void
** node					- Specific Node to Rotate
** tree					- Use Root Node as a Reference Node in Specific Case
** x					- The Input Node
** y					- The Right Child Node of the Input Node
** parent				- The Parent Node of the Input Node
*/

void	left_rotate(t_rb *tree, t_node *node)
{
	t_node	*x;
	t_node	*y;
	t_node	*parent;

	x = node;
	y = node->right;
	parent = get_parent(node);
	if (parent == NULL)
		tree->root = y;
	else
	{
		if (parent->left == x)
			parent->left = y;
		else
			parent->right = y;
	}
	set_parent(y, parent);
	set_parent(x, y);
	x->right = y->left;
	if (y->left != NULL)
		set_parent(y->left, x);
	y->left = x;
}

/*
** right_rotate ()		- Rotate the Tree to the Right Direction
**
** return				- void
** node					- Specific Node to Rotate
** tree					- Use Root Node as a Reference Node in Specific Case
** x					- The Input Node
** y					- The Left Child Node of the Input Node
** parent				- The Parent Node of the Input Node
*/

void	right_rotate(t_rb *tree, t_node *node)
{
	t_node	*x;
	t_node	*y;
	t_node	*parent;

	x = node;
	y = node->left;
	parent = get_parent(node);
	if (parent == NULL)
		tree->root = y;
	else
	{
		if (parent->left == x)
			parent->left = y;
		else
			parent->right = y;
	}
	set_parent(y, parent);
	set_parent(x, y);
	x->left = y->right;
	if (y->right != NULL)
		set_parent(y->right, x);
	y->right = x;
}

/*
** transplant ()		- Transplant the Node with New One
**
** return				- void
** tree					- RB Tree
** u					- A Old Node
** v					- A New Node
*/

void	transplant(t_rb *tree, t_node *u, t_node *v)
{
	if (get_parent(u) == NULL)
		tree->root = v;
	else
	{
		if (u == get_parent(u)->left)
			get_parent(u)->left = v;
		else
			get_parent(u)->right = v;
	}
	if (v != NULL)
		v->parent = get_parent(u);
}
