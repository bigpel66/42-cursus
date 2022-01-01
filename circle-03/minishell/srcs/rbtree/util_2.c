/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 22:33:47 by jseo              #+#    #+#             */
/*   Updated: 2022/01/01 12:38:30 by jseo             ###   ########.fr       */
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

	rb_assert(tree != NULL, \
		RASSERT "(tree != NULL), " SET_CHILD RUTIL_2_FILE "line 29.");
	res = tree->compare(node->key, child->key);
	rb_assert(res, \
		RASSERT "(res), " SET_CHILD RUTIL_2_FILE "line 32.");
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
		RASSERT "(node != NULL), " GET_MIN RUTIL_2_FILE "line 47.");
	while (node->left != NULL)
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
		RASSERT "(node != NULL), " GET_MAX RUTIL_2_FILE "line 63.");
	while (node->right != NULL)
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
	rb_assert(tree != NULL, \
		RASSERT "(tree != NULL), " MIN_ELEMENT RUTIL_2_FILE "line 81.");
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
	rb_assert(tree != NULL, \
		RASSERT "(tree != NULL), " MAX_ELEMENT RUTIL_2_FILE "line 97.");
	if (tree->root == NULL)
		return (NULL);
	return (get_max(tree->root));
}
