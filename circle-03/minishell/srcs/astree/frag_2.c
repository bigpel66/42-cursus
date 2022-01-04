/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frag_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:17:16 by jseo              #+#    #+#             */
/*   Updated: 2022/01/04 17:32:47 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astree.h"

/*
** insert_lt ()			- Insert Logic (Type of New Syntax Node LT)
**
** return				- Root Syntax Node
** root					- Input Root Syntax Node
** frag					- Specific Syntax Node
*/

static inline t_as	*insert_lt(t_as *root, t_as *frag)
{
	frag->right = root;
	return (frag);
}

/*
** insert_eq ()			- Insert Logic (Type of New Syntax Node EQ)
**
** return				- Root Syntax Node
** root					- Input Root Syntax Node
** frag					- Specific Syntax Node
*/

static inline t_as	*insert_eq(t_as *root, t_as *frag)
{
	if (frag->type == SCLN || frag->type == PIPE
		|| (frag->heredoc && !root->heredoc))
	{
		frag->right = root;
		return (frag);
	}
	root->right = as_insert(root->right, frag);
	return (root);
}

/*
** insert_gt ()			- Insert Logic (Type of New Syntax Node GT)
**
** return				- Root Syntax Node
** root					- Input Root Syntax Node
** frag					- Specific Syntax Node
*/

static inline t_as	*insert_gt(t_as *root, t_as *frag)
{
	if (root->type == PIPE)
	{
		if (root->right != NULL)
			root->left = as_insert(root->left, frag);
		else
			root->right = as_insert(root->right, frag);
	}
	else if (root->type == RDR)
	{
		if (root->left == NULL)
			root->left = as_insert(root->left, frag);
		else
			root->right = as_insert(root->right, frag);
	}
	return (root);
}

/*
** as_insert ()			- Insert the Syntax Node
**
** return				- Root Syntax Node of AS Tree
** syntax				- AS Tree
** frag					- Specific Syntax Node
** root					- Root Syntax Node of AS Tree
*/

t_as	*as_insert(t_as *syntax, t_as *frag)
{
	t_as	*root;

	if (syntax == NULL)
		return (frag);
	root = syntax;
	if (frag->type < root->type)
		root = insert_lt(root, frag);
	else if (frag->type == root->type)
		root = insert_eq(root, frag);
	else
		root = insert_gt(root, frag);
	return (root);
}

/*
** as_free ()			- Free AS Tree
**
** return				- void
*/

void	as_free(t_as *syntax)
{
	if (syntax->right != NULL)
		as_free(syntax->right);
	if (syntax->left != NULL)
		as_free(syntax->left);
	jfree((void **)(&syntax));
}
