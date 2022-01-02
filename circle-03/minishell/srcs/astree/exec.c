/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 02:47:20 by jseo              #+#    #+#             */
/*   Updated: 2022/01/02 19:26:11 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astree.h"

/*
** rollback ()			- Rollback FDs and Close
**
** return				- void
** fd0					- FD of Pointing STDIN
** fd1					- FD of Pointing STDOUT
** ret					- Return Value of Dup2 Function
*/

static inline void	rollback(int fd0, int fd1)
{
	int	ret;

	ret = dup2(fd0, STDIN_FILENO);
	as_assert(ret != ERROR, \
		AASSERT "(ret != ERROR), " ROLLBACK AEXEC_FILE "line 20.");
	ret = dup2(fd1, STDOUT_FILENO);
	as_assert(ret != ERROR, \
		AASSERT "(ret != ERROR), " ROLLBACK AEXEC_FILE "line 23.");
	close(fd0);
	close(fd1);
}

/*
** as_exec ()			- Execute AS Tree
**
** return				- void
** syntax				- AS Tree
** frag					- Specific Syntax Node
** envmap				- Variable for Maps the Environment Variables
** fd[2]				- Saved original STDIN & STDOUT
*/

void	as_exec(t_as *syntax, t_rb *envmap)
{
	int		fd[2];

	fd[0] = dup(STDIN_FILENO);
	fd[1] = dup(STDOUT_FILENO);
	as_assert(fd[0] != ERROR && fd[1] != ERROR, \
		AASSERT "(fd[0] != ERROR && fd[1] != ERROR), " \
		AS_EXEC AEXEC_FILE "line 35.");
	if (!as_check(syntax))
		jputendl(SYNTAX, STDERR_FILENO);
	else
		syntax->exec(syntax, envmap);
	rollback(fd[0], fd[1]);
}
