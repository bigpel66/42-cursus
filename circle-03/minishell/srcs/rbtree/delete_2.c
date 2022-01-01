/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 21:55:42 by jseo              #+#    #+#             */
/*   Updated: 2022/01/01 12:38:53 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rbtree.h"

/*
** case_4 ()			- Delete Case 4
**
** return				- void
** tree					- RB Tree
** node					- A Node to Delete
*/

static inline void	case_4(t_rb *tree, t_node *node)
{
	set_color(get_sibling(node), get_color(get_parent(node)));
	set_color(get_parent(node), BLACK);
	if (node == get_parent(node)->left)
	{
		rb_assert(get_color(get_sibling(node)->right) == RED, \
			RASSERT "get_color(get_sibling(node)->right) == RED, " CASE_4 \
			RDELETE_2_FILE "line 29.");
		set_color(get_sibling(node)->right, BLACK);
		left_rotate(tree, get_parent(node));
	}
	else
	{
		rb_assert(get_color(get_sibling(node)->left) == RED, \
			RASSERT "get_color(get_sibling(node)->left) == RED, " CASE_4 \
			RDELETE_2_FILE "line 37.");
		set_color(get_sibling(node)->left, BLACK);
		right_rotate(tree, get_parent(node));
	}
}

/*
** case_3 ()			- Delete Case 3
**
** return				- void
** tree					- RB Tree
** node					- A Node to Delete
*/

static inline void	case_3(t_rb *tree, t_node *node)
{
	if (node == get_parent(node)->left
		&& get_color(get_sibling(node)) == BLACK
		&& get_color(get_sibling(node)->left) == RED
		&& get_color(get_sibling(node)->right) == BLACK)
	{
		set_color(get_sibling(node), RED);
		set_color(get_sibling(node)->left, BLACK);
		right_rotate(tree, get_sibling(node));
	}
	else if (node == get_parent(node)->right
		&& get_color(get_sibling(node)) == BLACK
		&& get_color(get_sibling(node)->left) == BLACK
		&& get_color(get_sibling(node)->right) == RED)
	{
		set_color(get_sibling(node), RED);
		set_color(get_sibling(node)->right, BLACK);
		left_rotate(tree, get_sibling(node));
	}
	case_4(tree, node);
}

/*
** case_2 ()			- Delete Case 2
**
** return				- void
** tree					- RB Tree
** node					- A Node to Delete
*/

static inline void	case_2(t_rb *tree, t_node *node)
{
	if (get_color(get_parent(node)) == RED
		&& get_color(get_sibling(node)) == BLACK
		&& get_color(get_sibling(node)->left) == BLACK
		&& get_color(get_sibling(node)->right) == BLACK)
	{
		set_color(get_sibling(node), RED);
		set_color(get_parent(node), BLACK);
	}
	else
		case_3(tree, node);
}

/*
** case_1 ()			- Delete Case 1
**
** return				- void
** tree					- RB Tree
** node					- A Node to Delete
*/

static inline void	case_1(t_rb *tree, t_node *node)
{
	if (get_parent(node) == NULL)
		return ;
	if (get_color(get_sibling(node)) == RED)
	{
		set_color(get_parent(node), RED);
		set_color(get_sibling(node), BLACK);
		if (node == get_parent(node)->left)
			left_rotate(tree, get_parent(node));
		else
			right_rotate(tree, get_parent(node));
	}
	if (get_color(get_parent(node)) == BLACK
		&& get_color(get_sibling(node)) == BLACK
		&& get_color(get_sibling(node)->left) == BLACK
		&& get_color(get_sibling(node)->right) == BLACK)
	{
		set_color(get_sibling(node), RED);
		case_1(tree, get_parent(node));
	}
	else
		case_2(tree, node);
}

/*
** delete_internal ()	- Delete Logic of RB Tree
**
** return				- void
** tree					- RB Tree
** node					- A Node to Delete
** child				- The Left / Right Child Node of the Node to be Deleted
*/

void	delete_internal(t_rb *tree, t_node *node, t_node *child)
{
	if (get_color(node) == BLACK)
	{
		set_color(node, get_color(child));
		case_1(tree, node);
	}
	transplant(tree, node, child);
	if (get_parent(node) == NULL && child != NULL)
		set_color(child, BLACK);
	jfree((void **)(&node));
}
