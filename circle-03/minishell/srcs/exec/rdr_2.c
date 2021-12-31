/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdr_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 20:32:52 by jseo              #+#    #+#             */
/*   Updated: 2021/12/31 21:07:33 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** exec_rdr_gt ()		- Redirection on >
**
** return				- void
** syntax				- Specific Syntax Node
** fd					- File Descriptor to Redirect
*/

void	exec_rdr_gt(t_as *syntax)
{
	int		fd;

	fd = open(syntax->left->token, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	mini_assert(fd >= 0, \
		MASSERT "(fd >= 0), " EXEC_RDR_GT MRDR_2_FILE "line 28.");
	mini_assert(dup2(fd, STDOUT_FILENO) != ERROR, \
		MASSERT "(dup2(fd, STDOUT_FILENO) != ERROR), " \
		EXEC_RDR_GT MRDR_2_FILE "line 30.");
	close(fd);
}

/*
** exec_rdr_lt ()		- Redirection on <
**
** return				- void
** syntax				- Specific Syntax Node
** fd					- File Descriptor to Redirect
*/

void	exec_rdr_lt(t_as *syntax)
{
	int		fd;

	fd = open(syntax->left->token, O_RDONLY, S_IRWXU);
	mini_assert(fd >= 0, \
		MASSERT "(fd >= 0), " EXEC_RDR_LT MRDR_2_FILE "line 49.");
	mini_assert(dup2(fd, STDIN_FILENO) != ERROR, \
		MASSERT "(dup2(fd, STDIN_FILENO) != ERROR), " \
		EXEC_RDR_LT MRDR_2_FILE "line 51.");
	close(fd);
}

/*
** exec_rdr_rshift ()	- Redirection on <<
**
** return				- void
** syntax				- Specific Syntax Node
** fd					- File Descriptor to Redirect
*/

void	exec_rdr_rshift(t_as *syntax)
{
	int		fd;

	fd = open(syntax->left->token, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
	mini_assert(fd >= 0, \
		MASSERT "(fd >= 0), " EXEC_RDR_RSHIFT MRDR_2_FILE "line 70.");
	mini_assert(dup2(fd, STDOUT_FILENO) != ERROR, \
		MASSERT "(dup2(fd, STDOUT_FILENO) != ERROR), " \
		EXEC_RDR_RSHIFT MRDR_2_FILE "line 72.");
	close(fd);
}

/*
** handle ()			- Handle File Redirection on >>
**
** return				- void
** fd					- File Descriptor to Redirect
** input				- Variable for a User Input
** envmap				- Variable for Maps the Environment Variables
*/

static inline void	handle(int fd, char *input, t_rb *envmap)
{
	input = expand(input, envmap, false);
	jputendl(input, fd);
	jfree((void **)(&input));
}

/*
** exec_rdr_lshift ()	- Redirection on >>
**
** return				- void
** syntax				- Specific Syntax Node
** envmap				- Variable for Maps the Environment Variables
** fd					- File Descriptor to Redirect
** input				- Variable for a User Input
*/

void	exec_rdr_lshift(t_as *syntax, t_rb *envmap)
{
	int		fd;
	char	*input;

	fd = open(HEREDOC, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	mini_assert(fd >= 0, \
		MASSERT "(fd >= 0), " EXEC_RDR_LSHIFT MRDR_2_FILE "line 110.");
	while (true)
	{
		input = readline("> ");
		if (!jstrncmp(input, syntax->left->token, BUFFER_SIZE))
			break ;
		mini_assert(input != NULL, \
			MASSERT "(input != NULL), " \
			EXEC_RDR_LSHIFT MRDR_2_FILE "line 117.");
		handle(fd, input, envmap);
	}
	jfree((void **)(&input));
	close(fd);
	fd = open(HEREDOC, O_RDONLY, S_IRWXU);
	mini_assert(fd >= 0, \
		MASSERT "(fd >= 0), " EXEC_RDR_LSHIFT MRDR_2_FILE "line 125.");
	mini_assert(dup2(fd, STDIN_FILENO) != ERROR, \
		MASSERT "(dup2(fd, STDOUT_FILENO) != ERROR), " \
		EXEC_RDR_LSHIFT MRDR_2_FILE "line 127.");
	close(fd);
}
