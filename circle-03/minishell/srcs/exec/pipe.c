/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:32:43 by jseo              #+#    #+#             */
/*   Updated: 2022/01/04 17:23:22 by hyson            ###   ########.fr       */
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

	set_signal(SIG_IGN, SIG_IGN);
	pid = fork();
	mini_assert(pid != ERROR, \
		MASSERT "(pid != ERROR), " OUT_PROCESS MPIPE_FILE "line 31.");
	if (!pid)
	{
		set_signal(SIG_DFL, SIG_DFL);
		close(fd[IN]);
		mini_assert(dup2(fd[OUT], STDOUT_FILENO) != ERROR, \
			MASSERT "(dup2(fd[OUT], STDOUT_FILENO) != ERROR)" \
			OUT_PROCESS MPIPE_FILE "line 37.");
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

	set_signal(SIG_IGN, SIG_IGN);
	pid = fork();
	mini_assert(pid != ERROR, \
		MASSERT "(pid != ERROR), " IN_PROCESS MPIPE_FILE "line 63.");
	if (!pid)
	{
		set_signal(SIG_DFL, SIG_DFL);
		close(fd[OUT]);
		mini_assert(dup2(fd[IN], STDIN_FILENO) != ERROR, \
			MASSERT "(dup2(fd[IN], STDIN_FILENO) != ERROR)" \
			IN_PROCESS MPIPE_FILE "line 69.");
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
		MASSERT "(pipe(fd) != ERROR), " EXEC_PIPE MPIPE_FILE "line 96.");
	rchild = out_process(syntax->right, envmap, fd);
	waitpid(rchild, NULL, 0);
	close(fd[OUT]);
	lchild = in_process(syntax->left, envmap, fd);
	waitpid(lchild, NULL, 0);
	close(fd[IN]);
	set_signal(customized, SIG_IGN);
}
