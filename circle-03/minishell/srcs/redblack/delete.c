/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:40:43 by jseo              #+#    #+#             */
/*   Updated: 2021/12/23 18:33:13 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rbtree.h"

/*
**		rb_d_recolor_left ()	- Recolor Node (in case of Left Side Node)
**
**		return					: void
**		t						: the node to be rotated
**		x						: the current focused node to be fixed
**		cousin					: the cousin of node x
**		parent					: the parent of node x
*/

void	rb_d_recolor_left(t_rb **t, t_rb **x, t_rb **cousin, t_rb **parent)
{
	if ((*cousin)->l->c == BLACK && (*cousin)->r->c == BLACK)
	{
		(*cousin)->c = RED;
		(*x) = *parent;
	}
	else
	{
		if ((*cousin)->r->c == BLACK)
		{
			(*cousin)->l->c = BLACK;
			(*cousin)->c = RED;
			rb_right(t, cousin);
			*cousin = (*parent)->r;
		}
		(*cousin)->c = (*parent)->c;
		(*parent)->c = BLACK;
		(*cousin)->r->c = BLACK;
		rb_left(t, parent);
		*x = *t;
	}
}

/*
**		rb_d_recolor_right ()	- Recolor Node (in case of Right Side Node)
**
**		return					: void
**		t						: the node to be rotated
**		x						: the current focused node to be fixed
**		cousin					: the cousin of node x
**		parent					: the parent of node x
*/

void	rb_d_recolor_right(t_rb **t, t_rb **x, t_rb **cousin, t_rb **parent)
{
	if ((*cousin)->l->c == BLACK && (*cousin)->r->c == BLACK)
	{
		(*cousin)->c = RED;
		(*x) = *parent;
	}
	else
	{
		if ((*cousin)->l->c == BLACK)
		{
			(*cousin)->r->c = BLACK;
			(*cousin)->c = RED;
			rb_left(t, cousin);
			*cousin = (*parent)->l;
		}
		(*cousin)->c = (*parent)->c;
		(*parent)->c = BLACK;
		(*cousin)->l->c = BLACK;
		rb_right(t, parent);
		*x = *t;
	}
}

/*
**		rb_d_fixup ()		- Fixup the RB Tree after Deleting a Node
**
**		return				: void
**		t					: the node to be fixed (the root node could be changed)
**		x					: the node which is the child of the deleted node
*/

void	rb_d_fixup(t_rb **t, t_rb **x)
{
	t_rb	*cousin;
	t_rb	*parent;

	while (*x != *t && (*x)->c == BLACK)
	{
		parent = (*x)->p;
		if (*x == parent->l)
			cousin = parent->r;
		else
			cousin = parent->l;
		if (cousin->c == RED)
		{
			cousin->c = BLACK;
			parent->c = BLACK;
			if (*x == parent->l && rb_left(t, &parent))
				cousin = parent->r;
			if (*x == parent->r && rb_right(t, &parent))
				cousin = parent->l;
		}
		if (*x == parent->l)
			rb_d_recolor_left(t, x, &cousin, &parent);
		else
			rb_d_recolor_right(t, x, &cousin, &parent);
	}
	(*x)->c = BLACK;
}

/*
**		rb_d_both_child ()	- Case of Node Has Both Child on Delete
**
**		return				: void
**		t					: the root node of the tree for transplant
**		z					: the node to be deleted from the tree
**		y					: the node which is the smallest right after z
**		x					: the right child of y
*/

void	rb_d_both_child(t_rb **t, t_rb **z, t_rb **y, t_rb **x)
{
	if ((*y)->p != *z)
	{
		rb_transplant(t, y, x);
		(*y)->r = (*z)->r;
		(*y)->r->p = *y;
	}
	rb_transplant(t, z, y);
	(*y)->l = (*z)->l;
	(*y)->l->p = *y;
	(*y)->c = (*z)->c;
}

/*
**		rb_delete ()		- Delete the Specific Node to Root of RB Tree
**
**		return				: the t_rb node which is the root node of RB Tree
**		t					: the root node of the tree
**		z					: the node to be deleted from the tree
*/

t_rb	*rb_delete(t_rb *t, t_rb *z)
{
	t_rb	*y;
	t_rb	*x;
	t_color	yoc;

	y = z;
	x = NULL;
	yoc = z->c;
	if (y->l == NULL && y->r != NULL)
		x = y->r;
	if (y->l != NULL && y->r == NULL)
		x = y->l;
	if (y->l == NULL || y->r == NULL)
		rb_transplant(&t, &y, &x);
	else
	{
		y = rb_min(y->r);
		yoc = y->c;
		x = y->r;
		rb_d_both_child(&t, &z, &y, &x);
	}
	if (yoc == BLACK)
		rb_d_fixup(&t, &x);
	return (t);
}
