/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:05:25 by jseo              #+#    #+#             */
/*   Updated: 2021/12/23 14:40:03 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rbtree.h"

/*
**		rb_order ()			- Print RB Tree with the Specific Order
**
**		return				: void
**		root				: root node of the tree
**		order				: order to traverse (pre, in, post)
*/

void	rb_order(t_rb *root, t_order order)
{
	if (root == NULL)
		return ;
	if (order == PREORDER)
		printf("%s\t:\t%s\n", root->key, root->val);
	rb_order(root->l, order);
	if (order == INORDER)
		printf("%s\t:\t%s\n", root->key, root->val);
	rb_order(root->r, order);
	if (order == POSTORDER)
		printf("%s\t:\t%s\n", root->key, root->val);
}

/*
**		rb_search ()		- Search the Key
**
**		return				: t_rb node which key is equal to the input key
**		root				: root node of the tree
**		key					: key to find from the tree
**		res					: diff between node val and input key val
*/

t_rb	*rb_search(t_rb *root, char *key)
{
	int		res;

	if (root == NULL)
		return (NULL);
	res = jstrncmp(root->key, key, BUFFER_SIZE);
	if (!res)
		return (root);
	else if (res > 0)
		return (rb_search(root->l, key));
	else
		return (rb_search(root->r, key));
}

/*
**		rb_min ()			- Find the Smallest Node
**
**		return				: t_rb node which has the smallest value
*/

t_rb	*rb_min(t_rb *root)
{
	while (root->l != NULL)
		root = root->l;
	return root;
}

/*
**		rb_max ()			- Find the Largest Node
**
**		return				: t_rb node which has the largest value
*/

t_rb	*rb_max(t_rb *root)
{
	while (root->r != NULL)
		root = root->r;
	return root;
}
