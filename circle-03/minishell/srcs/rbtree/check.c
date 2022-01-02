/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:51:48 by jseo              #+#    #+#             */
/*   Updated: 2022/01/02 10:35:59 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rbtree.h"

/*
** rb_assert ()			- Assert Whether Condition True or False
**
** return				- void
** condition			- Condition to Check
** context				- Context Information in Runtime
*/

void	rb_assert(bool condition, char *context)
{
	if (condition)
		return ;
	jputendl(context, STDERR_FILENO);
	exit(GENERAL);
}

/*
** is_root ()			- Check Whether the Node Equal to Root
**
** return				- True or False
** node					- Specific Node
*/

bool	is_root(t_node *node)
{
	rb_assert(node != NULL, \
		RASSERT "(node != NULL), " IS_ROOT RCHECK_FILE "line 40.");
	return (get_parent(node) == NULL);
}

/*
** is_black ()			- Check the Color of the Node Equal to Black
**
** return				- True of False
** node					- Specific Node
*/

bool	is_black(t_node *node)
{
	rb_assert(node != NULL, \
		RASSERT "(node != NULL), " IS_BLACK RCHECK_FILE "line 54.");
	return (get_color(node) == BLACK);
}

/*
** is_red ()			- Check the Color of the Node Equal to Red
**
** return				- True or False
** node					- Specific Node
*/

bool	is_red(t_node *node)
{
	rb_assert(node != NULL, \
		RASSERT "(node != NULL), " IS_RED RCHECK_FILE "line 69.");
	return (get_color(node) == RED);
}

/*
** rb_compare ()		- Compare Function for RB Tree on String Data
**
** return				- Compare Value
** key_a				- Key First
** key_b				- Key Second
*/

int	rb_compare(void *key_a, void *key_b)
{
	return (jstrncmp((char *)key_a, (char *)key_b, BUFFER_SIZE));
}
