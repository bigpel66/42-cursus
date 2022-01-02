/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:35:07 by jseo              #+#    #+#             */
/*   Updated: 2022/01/02 10:36:26 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_H
# define RBTREE_H

/*
** =============================================================================
** Dependencies from User
** =============================================================================
*/

# include "jfunction.h"
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

# define RASSERT			"Assertion failed: "

# define IS_ROOT			"function is_root, "
# define IS_BLACK			"function is_black, "
# define IS_RED				"function is_red, "

# define RB_DELETE			"function rb_delete, "
# define CASE_4				"function case_4, "

# define RB_INIT			"function rb_init, "
# define MAKE_NODE			"function make_node, "
# define RB_INSERT			"function rb_insert, "

# define GET_NODE			"function get_node, "
# define GET_VALUE			"function get_value, "

# define SET_COLOR			"function set_color, "
# define GET_PARENT			"function get_parent, "
# define SET_PARENT			"function set_parent, "
# define GET_SIBLING		"function get_sibling, "

# define SET_CHILD			"function set_child, "
# define GET_MIN 			"function get_min, "
# define GET_MAX			"function get_max, "
# define MIN_ELEMENT		"function min_element, "
# define MAX_ELEMENT		"function max_element, "

# define PREV_ELEMENT		"function prev_element, "
# define NEXT_ELEMENT		"function next_element, "

# define RCHECK_FILE		"file rbtree/check.c, "
# define RDELETE_1_FILE		"file rbtree/delete_1.c, "
# define RDELETE_2_FILE		"file rbtree/delete_2.c, "
# define RINSERT_1_FILE		"file rbtree/insert_1.c, "
# define RSEARCH_FILE		"file rbtree/search.c, "
# define RUTIL_1_FILE		"file rbtree/util_1.c, "
# define RUTIL_2_FILE		"file rbtree/util_2.c, "
# define RUTIL_3_FILE		"file rbtree/util_3.c, "

/*
** =============================================================================
** Function Type Definitions
** =============================================================================
*/

typedef int	(*t_rb_cmp_fn)(void *key_a, void *key_b);

/*
** =============================================================================
** Struct Type Definitions
** =============================================================================
*/

typedef struct s_node
{
	void			*key;
	void			*value;
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
int		rb_compare(void *key_a, void *key_b);

/*
** =============================================================================
** Delete Functions
** =============================================================================
*/

void	rb_delete(t_rb *tree, void *key);
void	delete_internal(t_rb *tree, t_node *node, t_node *child);

/*
** =============================================================================
** Insert Functions
** =============================================================================
*/

t_rb	*rb_init(t_rb_cmp_fn compare);
t_node	*make_node(void *key, void *value);
void	rb_insert(t_rb *tree, void *key, void *value);
void	insert_internal(t_rb *tree, t_node *node, t_node *parent);

/*
** =============================================================================
** Print Functions
** =============================================================================
*/

void	rb_node(t_node *node, int level);
void	rb_print(t_rb *tree);
void	rb_order(t_node *node);

/*
** =============================================================================
** Search Functions
** =============================================================================
*/

t_node	*get_node(t_rb *tree, void *key, t_node **parent);
void	*get_value(t_rb *tree, void *key);

/*
** =============================================================================
** Utility Functions
** =============================================================================
*/

t_color	get_color(t_node *node);
void	set_color(t_node *node, t_color color);
t_node	*get_parent(t_node *node);
void	set_parent(t_node *node, t_node *parent);
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
