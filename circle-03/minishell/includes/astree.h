/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:38:26 by jseo              #+#    #+#             */
/*   Updated: 2021/12/25 12:50:40 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTREE_H
# define ASTREE_H

/*
** =============================================================================
** Function Type Definitions
** =============================================================================
*/

typedef void (*t_as_exec_fn)(void);

/*
** =============================================================================
** Enum Type Definitions
** =============================================================================
*/

typedef enum e_syntax
{
	WORD,
	RDR,
	PIPE,
	SCLN,
}					t_syntax;

/*
** =============================================================================
** Struct Type Definitions
** =============================================================================
*/

typedef struct s_as
{
	char			*token;
	t_syntax		syntax;
	t_as_exec_fn	exec;
	struct s_as		*left;
	struct s_as		*right;
}					t_as;

#endif
