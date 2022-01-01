/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:43:10 by jseo              #+#    #+#             */
/*   Updated: 2022/01/01 17:30:13 by jseo             ###   ########.fr       */
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
# include <fcntl.h>
# include <signal.h>
# include <readline/history.h>
# include <readline/readline.h>

/*
** =============================================================================
** Macros
** =============================================================================
*/

# define MASSERT			"Assertion failed: "

# define OUT_PROCESS		"function out_process, "
# define IN_PROCESS			"function in_process, "
# define EXEC_PIPE			"function exec_pipe, "

# define EXEC_RDR_GT		"function exec_rdr_gt, "
# define EXEC_RDR_LT		"function exec_rdr_lt, "
# define EXEC_RDR_RSHIFT	"function exec_rdr_rshift, "
# define EXEC_RDR_LSHIFT	"function exec_rdr_lshift, "

# define EXPAND_SPACE		"function expand_space, "
# define EXPAND_BRACE		"function expand_brace, "
# define EXPAND_MIDDLE		"function expand_middle, "

# define PAIR_ARGV			"function pair_argv, "

# define TOKENIZE_INTERNAL	"function tokenize_internal, "

# define LOOP				"function loop, "

# define MPIPE_FILE			"file exec/pipe.c, "
# define MRDR_2_FILE		"file exec/rdr_2.c, "
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
** Command Functions
** =============================================================================
*/

void	add(char ***args, char *chunk);
void	arrange(char *chunk);;
char	**capture(t_as *syntax);
char	**configure(t_rb *envmap);
void	delete(char ***args);
char	*find(char *command, t_rb *envmp);
void	finish(void);
char	*resolve(char *input, t_rb *envmap);
void	exec_cmd(t_as *syntax, t_rb *envmap);

/*
** =============================================================================
** Pipe Functions
** =============================================================================
*/

void	exec_pipe(t_as *syntax, t_rb *envmap);

/*
** =============================================================================
** Redirection Functions
** =============================================================================
*/

void	exec_rdr_gt(t_as *syntax);
void	exec_rdr_lt(t_as *syntax);
void	exec_rdr_rshift(t_as *syntax);
void	exec_rdr_lshift(t_as *syntax, t_rb *envmap);
void	exec_rdr(t_as *syntax, t_rb *envmap);

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
