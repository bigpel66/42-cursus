/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:43:10 by jseo              #+#    #+#             */
/*   Updated: 2021/12/31 17:00:49 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
** =============================================================================
** Dependencies from User
** =============================================================================
*/

# include "astree.h"

/*
** =============================================================================
** Dependencies from System
** =============================================================================
*/

# include <dirent.h>
# include <signal.h>
# include <readline/history.h>
# include <readline/readline.h>

/*
** =============================================================================
** Macros
** =============================================================================
*/

# define MASSERT			"Assertion failed: "

# define EXPAND_SPACE		"function expand_space, "
# define EXPAND_BRACE		"function expand_brace, "
# define EXPAND_MIDDLE		"function expand_middle, "

# define PAIR_ARGV			"function pair_argv, "

# define TOKENIZE_INTERNAL	"function tokenize_internal, "

# define LOOP				"function loop, "

# define MEXPAND_1_FILE		"file parse/expand_1.c, "
# define MPAIR_FILE			"file parse/pair.c, "
# define MTOKENIZE_FILE		"file parse/expand_1.c, "
# define MLOOP_FILE			"file runtime/loop.c, "

/*
** =============================================================================
** Builtin Functions
** =============================================================================
*/

int		builtin_cd(char **args, t_rb *envmap);
int		builtin_echo(char **args);
int		builtin_env(t_rb *envmap);
int		builtin_exit(char **args);
int		builtin_export(char **args, t_rb *envmap);
int		builtin_pwd(void);
int		builtin_unset(char **args, t_rb *envmap);

/*
** =============================================================================
** Expand Functions (Parse)
** =============================================================================
*/

char	*expand(char *input, t_rb *envmap, bool d_quote);
char	*expand_internal(char *input, char *iter, t_rb *envmap, bool d_quote);

/*
** =============================================================================
** Pair Functions (Parse)
** =============================================================================
*/

void	pair(int argc, char **argv, char **envp, t_rb *envmap);

/*
** =============================================================================
** Tokenize Functions (Parse)
** =============================================================================
*/

void	tokenize(char *input, t_lst **chunks);
char	*tokenize_internal(char *input, char *begin, char *end, t_lst **chunks);

/*
** =============================================================================
** Runtime Functions
** =============================================================================
*/

void	mini_assert(bool condition, char *context);
void	loop(char *input, t_lst *chunks, t_as *syntax, t_rb *envmap);

#endif
