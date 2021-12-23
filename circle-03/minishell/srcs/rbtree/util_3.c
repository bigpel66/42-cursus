/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 22:53:49 by jseo              #+#    #+#             */
/*   Updated: 2021/12/24 00:41:46 by jseo             ###   ########.fr       */
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
		ASSERT "(node != NULL), " PREV_ELEMENT RB_UTIL_3 "line 27.");
	if (node->left)
		return (get_max(node->left));
	parent = get_parent(node);
	while (parent && parent->left == node)
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
		ASSERT "(node != NULL), " NEXT_ELEMENT RB_UTIL_3 "line 52.");
	if (node->right)
		return (get_min(node->right));
	parent = get_parent(node);
	while (parent && parent->right == node)
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
	parent = node->parent;
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
	if (y->left)
		set_parent(y->left, x);
	y->left = x;
}

/*
** right_rotate ()		- Rotate the Tree to the Right Direction
**
** return				-	void
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
	parent = node->parent;
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
	if (y->right)
		set_parent(y->right, x);
	y->right = x;
}

/*
** transplant ()		- Transplant the Node with New One
**
** return				- void
** tree					- RB Tree
** u					- a Old Node
** v					- a New Node
*/

void	transplant(t_rb *tree, t_node *u, t_node *v)
{
	if (u->parent == NULL)
		tree->root = v;
	else
	{
		if (u == u->parent->left)
			u->parent->left = v;
		else
			u->parent->right = v;
	}
	if (v != NULL)
		v->parent = u->parent;
}
