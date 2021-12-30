/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:38:26 by jseo              #+#    #+#             */
/*   Updated: 2021/12/30 16:35:42 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTREE_H
# define ASTREE_H

/*
** =============================================================================
** Dependencies from User
** =============================================================================
*/

# include "rbtree.h"

/*
** =============================================================================
** Macros
** =============================================================================
*/

# define AASSERT			"Assertion failed: "

# define AS_INIT			"function as_init, "
# define ROLLBACK			"function rollback, "
# define AS_EXEC			"funciton as_exec, "

# define AFRAG_1_FILE		"file astree/frag_1.c, "
# define AEXEC_FILE			"file astree/exec.c, "

/*
** =============================================================================
** Function Type Definitions
** =============================================================================
*/

typedef void (*t_as_exec_fn)();

/*
** =============================================================================
** Enum Type Definitions
** =============================================================================
*/

typedef enum e_type
{
	SCLN = -1,
	PIPE,
	RDR,
	CMD,
}					t_type;

/*
** =============================================================================
** Struct Type Definitions
** =============================================================================
*/

typedef struct s_as
{
	char			*token;
	t_type			type;
	t_as_exec_fn	exec;
	struct s_as		*left;
	struct s_as		*right;
}					t_as;

/*
** =============================================================================
** Check Functions
** =============================================================================
*/

void	as_assert(bool condition, char *context);
bool	as_check(t_as *syntax);
void	as_syntax(t_as *syntax, int level);
void	as_print(t_as *syntax);

/*
** =============================================================================
** Exec Functions
** =============================================================================
*/

void	as_exec(t_as *syntax, t_rb *envmap);

/*
** =============================================================================
** Exec Plan Functions
** =============================================================================
*/

void	exec_cmd(t_as *syntax, t_rb *envmap);
void	exec_pipe(t_as *syntax, t_rb *envmap);
void	exec_rdr(t_as *syntax, t_rb *envmap);

/*
** =============================================================================
** Frag Functions
** =============================================================================
*/

t_as	*as_init(t_lst *chunks);
t_as	*make_frag(t_lst *chunk);
t_as	*as_insert(t_as *syntax, t_as *frag);
void	as_free(t_as *syntax);

#endif
