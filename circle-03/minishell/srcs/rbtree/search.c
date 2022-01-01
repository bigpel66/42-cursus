/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 10:45:11 by jseo              #+#    #+#             */
/*   Updated: 2022/01/01 12:38:45 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rbtree.h"

/*
** get_node				- Getting the Node Equal to Key
**
** return				- The Exact Node or NULL
** tree					- RB Tree
** key					- Key to Find the Node
** parent				- Record the Parent Node (If Exists)
** res					- Result of Comparing 2 Keys
** current				- Current Node from Root Node of the RB Tree
*/

t_node	*get_node(t_rb *tree, void *key, t_node **parent)
{
	int		res;
	t_node	*current;

	rb_assert(tree != NULL, \
		RASSERT "(tree != NULL), " GET_NODE RSEARCH_FILE "line 31.");
	current = tree->root;
	while (current != NULL)
	{
		res = tree->compare(current->key, key);
		if (!res)
			return (current);
		else
		{
			if (parent != NULL)
				*parent = current;
			if (res > 0)
				current = current->left;
			else
				current = current->right;
		}
	}
	return (NULL);
}

/*
** get_value			- Getting the Value of the Key
**
** return				- Value from RB Tree Corresponding to the Key
** tree					- RB Tree
** key					- Key to Find the Value
** node					- Searched Node
*/

void	*get_value(t_rb *tree, void *key)
{
	t_node	*node;

	rb_assert(tree != NULL, \
		RASSERT "(tree != NULL), " GET_VALUE RSEARCH_FILE "line 66.");
	node = get_node(tree, key, NULL);
	if (node == NULL)
		return (NULL);
	return (node->value);
}
