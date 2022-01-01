/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:32:43 by jseo              #+#    #+#             */
/*   Updated: 2022/01/01 12:38:06 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** out_process ()		- Execute the Command of Right Child (Out)
**
** return				- Process ID of Right Child
** syntax				- Specific Syntax Node
** envmap				- Variable for Maps the Environment Variables
** fd[2]				- File Descriptor for Piping 2 Child Processes
** pid					- Process ID of Right Child
*/

static inline pid_t	out_process(t_as *syntax, t_rb *envmap, int fd[2])
{
	pid_t	pid;

	pid = fork();
	mini_assert(pid != ERROR, \
		MASSERT "(pid != ERROR), " OUT_PROCESS MPIPE_FILE "line 30.");
	if (!pid)
	{
		close(fd[IN]);
		mini_assert(dup2(fd[OUT], STDOUT_FILENO) != ERROR, \
			MASSERT "(dup2(fd[OUT], STDOUT_FILENO) != ERROR)" \
			OUT_PROCESS MPIPE_FILE "line 35.");
		close(fd[OUT]);
		syntax->exec(syntax, envmap);
		exit(VALID);
	}
	return (pid);
}

/*
** in_process ()		- Execute the Command of Left Child (In)
**
** return				- Process ID of Left Child
** syntax				- Specific Syntax Node
** envmap				- Variable for Maps the Environment Variables
** fd[2]				- File Descriptor for Piping 2 Child Processes
** pid					- Process ID of Left Child
*/

static inline pid_t	in_process(t_as *syntax, t_rb *envmap, int fd[2])
{
	pid_t	pid;

	pid = fork();
	mini_assert(pid != ERROR, \
		MASSERT "(pid != ERROR), " IN_PROCESS MPIPE_FILE "line 60.");
	if (!pid)
	{
		close(fd[OUT]);
		mini_assert(dup2(fd[IN], STDIN_FILENO) != ERROR, \
			MASSERT "(dup2(fd[IN], STDIN_FILENO) != ERROR)" \
			IN_PROCESS MPIPE_FILE "line 65.");
		close(fd[IN]);
		syntax->exec(syntax, envmap);
		exit(VALID);
	}
	return (pid);
}

/*
** exec_pipe ()			- Execute Function on Syntax Pipe
**
** return				- void
** syntax				- Specific Syntax Node
** envmap				- Variable for Maps the Environment Variables
** fd[2]				- File Descriptor for Piping 2 Child Processes
** lchild				- After Child (which is Left Child of AS Tree)
** rchild				= Before Child (which is Right Child of AS Tree)
*/

void	exec_pipe(t_as *syntax, t_rb *envmap)
{
	int		fd[2];
	pid_t	lchild;
	pid_t	rchild;

	mini_assert(pipe(fd) != ERROR, \
		MASSERT "(pipe(fd) != ERROR), " EXEC_PIPE MPIPE_FILE "line 92.");
	rchild = out_process(syntax->right, envmap, fd);
	lchild = in_process(syntax->left, envmap, fd);
	close(fd[IN]);
	close(fd[OUT]);
	waitpid(rchild, NULL, 0);
	waitpid(lchild, NULL, 0);
}
