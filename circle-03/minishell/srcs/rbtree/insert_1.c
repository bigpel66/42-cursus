/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 12:10:02 by jseo              #+#    #+#             */
/*   Updated: 2022/01/01 12:38:52 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rbtree.h"

/*
** rb_init ()			- Initiation to Use RB Tree
**
** return				- RB Tree
** compare				- Function to Compare the Key of Node in the Tree
** tree					- RB Tree
*/

t_rb	*rb_init(t_rb_cmp_fn compare)
{
	t_rb	*tree;

	jcalloc((void **)(&tree), 1, sizeof(t_rb));
	rb_assert(tree != NULL, \
		RASSERT "(tree != NULL), " RB_INIT RINSERT_1_FILE "line 28.");
	tree->root = NULL;
	rb_assert(compare != NULL, \
		RASSERT "(compare != NULL), " RB_INIT RINSERT_1_FILE "line 31.");
	tree->compare = compare;
	return (tree);
}

/*
** make_node ()			- Create a New Node for Using in RB Tree
**
** return				- A New Node with Key and Value
** key					- Key of a New Node
** value				- Value of a New Node
** node					- A New Node
*/

t_node	*make_node(void *key, void *value)
{
	t_node	*node;

	jcalloc((void **)(&node), 1, sizeof(t_node));
	rb_assert(node != NULL, \
		RASSERT "(node != NULL), " MAKE_NODE RINSERT_1_FILE "line 51.");
	node->key = key;
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	return (node);
}

/*
** rb_insert ()			- Insert the Key and Value
**
** return				- void
** tree					- RB Tree
** key					- Key
** value				- Value
** parent				- Parent of the Node to Insert
** node					- A New Node
** prev					- Already Existing Node
*/

void	rb_insert(t_rb *tree, void *key, void *value)
{
	t_node	*parent;
	t_node	*node;
	t_node	*prev;

	parent = NULL;
	rb_assert(key != NULL && value != NULL, RASSERT \
		"(key != NULL && value != NULL), " RB_INSERT RINSERT_1_FILE "line 80.");
	prev = get_node(tree, key, &parent);
	if (prev != NULL)
	{
		jfree((void **)(&key));
		jfree((void **)(&(prev->value)));
		prev->value = value;
	}
	else
	{
		node = make_node(key, value);
		set_color(node, RED);
		set_parent(node, parent);
		if (parent == NULL)
			tree->root = node;
		else
			set_child(tree, parent, node);
		insert_internal(tree, node, parent);
	}
}
