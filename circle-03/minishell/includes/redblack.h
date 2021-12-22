/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redblack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:35:07 by jseo              #+#    #+#             */
/*   Updated: 2021/12/22 18:39:08 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACK_H
# define REDBLACK_H

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

/*
** =============================================================================
** Struct Type Definitions
** =============================================================================
*/

typedef struct s_rb
{
	char			*key;
	char			*val;
	t_color			c;
	struct s_rb		*l;
	struct s_rb		*r;
	struct s_rb		*p;
}					t_rb;

/*
** =============================================================================
** Map Functions
** =============================================================================
*/

void	rb_left(t_rb **t, t_rb **x);
void	rb_right(t_rb **t, t_rb **x);
void	rb_transplant(t_rb **t, t_rb **u, t_rb **v);
void	rb_i_fixup(t_rb **t, t_rb **z);
t_rb	*rb_insert(t_rb *t, char *key, char *val);
void	rb_d_fixup(t_rb **t, t_rb **x);
t_rb	*rb_delete(t_rb *t, t_rb *z);
t_rb	*rb_search(t_rb *root, char *key);
void	rb_clear(t_rb **root);

#endif
