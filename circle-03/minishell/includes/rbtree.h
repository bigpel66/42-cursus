/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:35:07 by jseo              #+#    #+#             */
/*   Updated: 2021/12/24 00:42:09 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_H
# define RBTREE_H

/*
** =============================================================================
** Dependencies from User
** =============================================================================
*/

# include "j_function.h"
# include "enumeration.h"

/*
** =============================================================================
** Dependencies from System
** =============================================================================
*/

# include <stdio.h>

/*
** =============================================================================
** Macros
** =============================================================================
*/

# define ASSERT			"Assertion failed: "

# define IS_ROOT		"function is_root, "
# define IS_BLACK		"function is_black, "
# define IS_RED			"function is_red, "

# define SET_COLOR		"function set_color, "
# define GET_PARENT		"function get_parent, "
# define SET_PARENT		"function set_parent, "
# define GET_SIBLING	"function get_sibling, "

# define SET_CHILD		"function set_child, "
# define GET_MIN 		"function get_min, "
# define GET_MAX		"function get_max, "
# define MIN_ELEMENT	"function min_element, "
# define MAX_ELEMENT	"function max_element, "

# define PREV_ELEMENT	"function prev_element, "
# define NEXT_ELEMENT	"function next_element, "
# define LEFT_ROTATE	"function left_rotate, "
# define RIGHT_ROTATE	"function right_rotate, "

# define RB_CHECK		"file rbtree/check.c, "
# define RB_UTIL_1		"file rbtree/util_1.c, "
# define RB_UTIL_2		"file rbtree/util_2.c, "
# define RB_UTIL_3		"file rbtree/util_3.c, "

/*
** =============================================================================
** Function Type Definitions
** =============================================================================
*/

typedef int (*t_rb_cmp_fn)(void *key_a, void *key_b);

/*
** =============================================================================
** Enum Type Definitions
** =============================================================================
*/

typedef enum e_color
{
	RED,
	BLACK,
}					t_color;

typedef enum e_order
{
	PREORDER,
	INORDER,
	POSTORDER,
}					t_order;

/*
** =============================================================================
** Struct Type Definitions
** =============================================================================
*/

typedef struct s_node
{
	void			*key;
	void			*val;
	t_color			color;
	struct s_node	*left;
	struct s_node	*right;
	struct s_node	*parent;
}					t_node;

typedef struct s_rb
{
	t_node			*root;
	t_rb_cmp_fn		compare;
}					t_rb;

/*
** =============================================================================
** Check Functions
** =============================================================================
*/

void	rb_assert(bool condition, char *context);
bool	is_root(t_node *node);
bool	is_black(t_node *node);
bool	is_red(t_node *node);

/*
** =============================================================================
** Utility Functions
** =============================================================================
*/

t_color	get_color(t_node *node);
void	set_color(t_node *node, t_color color);
t_node	*get_parent(t_node *node);
t_node	*set_parent(t_node *node, t_node *parent);
t_node	*get_sibling(t_node *node);

void	set_child(t_rb *tree, t_node *node, t_node *child);
t_node	*get_min(t_node *node);
t_node	*get_max(t_node *node);
t_node	*min_element(t_rb *tree);
t_node	*max_element(t_rb *tree);

t_node	*prev_element(t_node *node);
t_node	*next_element(t_node *node);
void	left_rotate(t_rb *tree, t_node *node);
void	right_rotate(t_rb *tree, t_node *node);
void	transplant(t_rb *tree, t_node *u, t_node *v);

#endif
