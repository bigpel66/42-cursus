/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 20:38:31 by jseo              #+#    #+#             */
/*   Updated: 2022/01/01 12:38:50 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rbtree.h"

/*
** rb_delete ()			- Delete the Key and Value
**
** return				- void
** tree					- RB Tree
** key					- Key
** node					- The Node to be Deleted
** next					- The Node to Change the Node to be Deleted
** child				- The Left / Right Child Node of the Node to be Deleted
*/

void	rb_delete(t_rb *tree, void *key)
{
	t_node	*node;
	t_node	*next;
	t_node	*child;

	node = get_node(tree, key, NULL);
	if (node == NULL)
		return ;
	if (node->left != NULL && node->right != NULL)
	{
		jfree((void **)(&(node->key)));
		jfree((void **)(&(node->value)));
		next = get_min(node->right);
		node->key = next->key;
		node->value = next->value;
		node = next;
	}
	rb_assert(node->left == NULL || node->right == NULL, \
		RASSERT "(node->left == NULL || node->right == NULL), " RB_DELETE \
		RDELETE_1_FILE "line 42.");
	if (node->right == NULL)
		child = node->left;
	else
		child = node->right;
	delete_internal(tree, node, child);
}
