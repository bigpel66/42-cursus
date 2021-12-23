/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:37:37 by jseo              #+#    #+#             */
/*   Updated: 2021/12/23 15:07:17 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rbtree.h"

/*
**		rb_new ()			- Allocate a New Node for RB Tree
**
**		return				: bool for allocating well or not
**		rb					: a position to allocate t_rb
**		key					: key of the new node
**		val					: val of the new node
*/

bool	rb_new(t_rb **rb, char *key, char *val)
{
	if (!jcalloc((void**)rb, 1, sizeof(t_rb)))
		return (false);
	(*rb)->key = key;
	(*rb)->k_len = jstrlen(key);
	(*rb)->val = val;
	(*rb)->v_len = jstrlen(val);
	(*rb)->l = NULL;
	(*rb)->r = NULL;
	(*rb)->p = NULL;
	(*rb)->c = RED;
	return (true);
}

/*
**		rb_i_recolor		- (If tree cannot be fixed by uncle) Recolor Node
**
**		return				: void
**		t					: the node to be rotated
**		z					: the current focused node to be fixed
**		parent				: the parent of node z
**		grandparent			: the grandparent of node z
*/

void	rb_i_recolor(t_rb **t, t_rb **z, t_rb **parent, t_rb **grandparent)
{
	if (*parent == (*grandparent)->l)
	{
		if (*z == (*parent)->r)
		{
			rb_left(t, parent);
			*z = *parent;
			*parent = (*z)->p;
		}
		rb_right(t, grandparent);
	}
	if (*parent == (*grandparent)->r)
	{
		if (*z == (*parent)->l)
		{
			rb_right(t, parent);
			*z = *parent;
			*parent = (*z)->p;
		}
		rb_left(t, grandparent);
	}
	(*parent)->c = BLACK;
	(*grandparent)->c = RED;
	*z = *parent;
}

/*
**		rb_i_fixup ()		- Fixup the RB Tree after Inserting a Node
**
**		return				: void
**		t					: the node to be fixed (the root node could be changed)
**		z					: the inserted new node
**		uncle				: the uncle node of z
**		parent				: the parent node of z
**		grandparent			: the grandparent node of z
*/

void	rb_i_fixup(t_rb **t, t_rb **z)
{
	t_rb	*uncle;
	t_rb	*parent;
	t_rb	*grandparent;

	while (*z != *t && (*z)->c != BLACK && (*z)->p->c == RED)
	{
		parent = (*z)->p;
		grandparent = (*z)->p->p;
		if (parent == grandparent->l)
			uncle = grandparent->r;
		else
			uncle = grandparent->l;
		if (uncle != NULL && uncle->c == RED)
		{
			grandparent->c = RED;
			parent->c = BLACK;
			uncle->c = BLACK;
			*z = grandparent;
		}
		else
			rb_i_recolor(t, z, &parent, &grandparent);
	}
	(*t)->c = BLACK;
}

/*
**		rb_insert ()		- Insert a New Node to the Root of RB Tree
**
**		return				: the t_rb node which is the root node of RB Tree
**		t					: the root node of the tree
**		key					: key of new node
**		val					: value of new node
**		z					: a new node to be inserted
**		y					: the node that is the exact point to insert node z
**		x					: the node to search the point to insert node z
*/

t_rb	*rb_insert(t_rb *t, char *key, char *val)
{
	t_rb	*z;
	t_rb	*y;
	t_rb	*x;

	if (!rb_new(&z, key, val))
		exit(GENERAL);
	y = NULL;
	x = t;
	while (x != NULL)
	{
		y = x;
		if (jstrncmp(x->key, z->key, BUFFER_SIZE) > 0)
			x = x->l;
		else
			x = x->r;
	}
	z->p = y;
	if (y == NULL)
		t = z;
	else if (jstrncmp(y->key, z->key, BUFFER_SIZE) > 0)
		y->l = z;
	else
		y->r = z;
	rb_i_fixup(&t, &z);
	return (t);
}
