/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:34:45 by jseo              #+#    #+#             */
/*   Updated: 2022/01/01 12:38:31 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rbtree.h"

/*
** get_color ()			- Getting Color of the Node
**
** return				- Color
** node					- Specific Node
*/

t_color	get_color(t_node *node)
{
	if (node == NULL)
		return (BLACK);
	return (node->color);
}

/*
** set_color ()			- Setting Color of the Node
**
** return				- void
** node					- Specific Node
** color				- Color
*/

void	set_color(t_node *node, t_color color)
{
	rb_assert(node != NULL, \
		RASSERT "(node != NULL), " SET_COLOR RUTIL_1_FILE "line 39.");
	node->color = color;
}

/*
** get_parent ()		- Getting the Parent Node
**
** return				- Parent Node
** node					- Specific Node
*/

t_node	*get_parent(t_node *node)
{
	rb_assert(node != NULL, \
		RASSERT "(node != NULL), " GET_PARENT RUTIL_1_FILE "line 53.");
	return (node->parent);
}

/*
** set_parent ()		- Setting the Parent Node
**
** return				- void
** node					- Specific Node
** parent				- Parent Node
*/

void	set_parent(t_node *node, t_node *parent)
{
	rb_assert(node != NULL, \
		RASSERT "(node != NULL), " SET_PARENT RUTIL_1_FILE "line 68.");
	node->parent = parent;
}

/*
** get_sibling ()		- Getting the Sibling Node
**
** return				- Sibling Node
** node					- Specific Node
*/

t_node	*get_sibling(t_node *node)
{
	rb_assert(node != NULL, \
		RASSERT "(node != NULL), " GET_SIBLING RUTIL_1_FILE "line 82.");
	rb_assert(node->parent != NULL, \
		RASSERT "(node->parent != NULL), " GET_SIBLING RUTIL_1_FILE "line 84.");
	if (node == get_parent(node)->left)
		return (get_parent(node)->right);
	return (get_parent(node)->left);
}
