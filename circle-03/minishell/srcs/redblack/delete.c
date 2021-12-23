/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:40:43 by jseo              #+#    #+#             */
/*   Updated: 2021/12/23 15:11:20 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rbtree.h"

void	rb_clear(t_rb **root)
{

}

/*
**		rb_i_fixup ()		- Fixup the RB Tree after Inserting a Node
**
**		return				: void
**		t					: the node to be fixed (the root node could be changed)
**		x					: the node which is the child of the deleted node
*/

void	rb_d_fixup(t_rb **t, t_rb **x)
{

}

/*
**		rb_delete ()		- Delete the Specific Node to Root of RB Tree
**
**		return				: the t_rb node which is the root node of RB Tree
**		t					: the root node of the tree
**		z					: the node to be deleted from the tree
*/

t_rb	*rb_delete(t_rb *t, t_rb *z)
{
	t_rb	*y;
	t_color	yoc;

	y = z;
	yoc = z->c;
}
