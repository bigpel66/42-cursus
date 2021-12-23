/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 22:33:47 by jseo              #+#    #+#             */
/*   Updated: 2021/12/24 00:36:41 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rbtree.h"

/*
** set_child ()			- Set the Child Node
**
** return				- void
** tree					- RB Tree to Use the Compare Function
** node					- Specific Node
** child				- Child Node
** ret					- Result of Comparing 2 Keys
*/

void	set_child(t_rb *tree, t_node *node, t_node *child)
{
	int	res;

	res = tree->compare(node->key, child->key);
	rb_assert(res != 0, \
		ASSERT "(res != 0), " SET_CHILD RB_UTIL_2 "line 30.");
	if (res > 0)
		node->left = child;
	else
		node->right = child;
}

/*
** get_min ()			- Get the Minimum Node from the Input Node
**
** return				- The Minimum Node
** node					- Specific Node
*/

t_node	*get_min(t_node *node)
{
	rb_assert(node != NULL, \
		ASSERT "(node != NULL), " GET_MIN RB_UTIL_2 "line 47.");
	while (node->left)
		node = node->left;
	return (node);
}

/*
** get_max ()			- Get the Maximum Node from the Input Node
**
** return				- The Maximum Node
** node					- Specific Node
*/

t_node	*get_max(t_node *node)
{
	rb_assert(node != NULL, \
		ASSERT "(node != NULL), " GET_MAX RB_UTIL_2 "line 63.");
	while (node->right)
		node = node->right;
	return (node);
}

/*
** min_element ()		- Get the Minimum Element from the RB Tree
**
** return				- The Minimum Node in the Tree
** tree					- RB Tree
*/

t_node	*min_element(t_rb *tree)
{
	if (tree->root == NULL)
		return (NULL);
	return (get_min(tree->root));
}

/*
** max_element ()		- Get the Maximum Element from the RB Tree
**
** return				- The Maximum Node in the Tree
** tree					- RB Tree
*/

t_node	*max_element(t_rb *tree)
{
	if (tree->root == NULL)
		return (NULL);
	return (get_max(tree->root));
}
