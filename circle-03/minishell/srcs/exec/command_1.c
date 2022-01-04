/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:32:40 by jseo              #+#    #+#             */
/*   Updated: 2022/01/04 18:56:33 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** is_builtin ()		- Check the Command Builtin or Not
**
** return				- True or False
** syntax				- Specific Syntax Node
** i					- Index to Iterate All Elements
** lower				- Command to be Lowercased
** builtin				- Whether Builtin or Not
*/

static inline bool	is_builtin(t_as *syntax)
{
	int		i;
	char	*lower;
	bool	builtin;

	i = -1;
	lower = jstrdup(syntax->token);
	builtin = false;
	mini_assert(lower != NULL, \
		MASSERT "(lower != NULL), " IS_BUILTIN MCOMMAND_1_FILE "line 34.");
	while (lower[++i])
		lower[i] = jtolower(lower[i]);
	if (!jstrncmp("cd", lower, BUFFER_SIZE)
		|| !jstrncmp("echo", lower, BUFFER_SIZE)
		|| !jstrncmp("env", lower, BUFFER_SIZE)
		|| !jstrncmp("exit", lower, BUFFER_SIZE)
		|| !jstrncmp("export", lower, BUFFER_SIZE)
		|| !jstrncmp("pwd", lower, BUFFER_SIZE)
		|| !jstrncmp("unset", lower, BUFFER_SIZE))
		builtin = true;
	jfree((void **)(&lower));
	return (builtin);
}

/*
** exec_builtin ()		- Execute Function on Builtin
**
** return				- Exit Code
** command				- Command to Execute
** args					- All Arguments to Execute the Command
** envmap				- Variable for Maps the Environment Variables
** i					- Index to Iterate All Characters of the Command
*/

static inline int	exec_builtin(char *command, char **args, t_rb *envmap)
{
	int		i;

	i = -1;
	while (command[++i])
		command[i] = jtolower(command[i]);
	if (!jstrncmp("cd", command, BUFFER_SIZE))
		return (builtin_cd(args, envmap));
	else if (!jstrncmp("echo", command, BUFFER_SIZE))
		return (builtin_echo(args));
	else if (!jstrncmp("env", command, BUFFER_SIZE))
		return (builtin_env(envmap));
	else if (!jstrncmp("exit", command, BUFFER_SIZE))
		return (builtin_exit(args));
	else if (!jstrncmp("export", command, BUFFER_SIZE))
		return (builtin_export(args, envmap));
	else if (!jstrncmp("pwd", command, BUFFER_SIZE))
		return (builtin_pwd());
	else if (!jstrncmp("unset", command, BUFFER_SIZE))
		return (builtin_unset(args, envmap));
	else
		return (BUILTIN);
}

/*
** binary_internal ()	- Execute Binary Logic
**
** return				- ID of Child Process
** command				- Command to Execute
** args					- All Arguments to Execute the Command
** envmap				- Variable for Maps the Environment Variables
** pid					- ID of Child Process
** path					- Path to Execute the Command
** envp					- Environment Variables to Execute the Command
*/

static inline pid_t	binary_internal(char *command, char **args, t_rb *envmap)
{
	pid_t	pid;
	char	*path;
	char	**envp;

	set_signal(SIG_IGN, SIG_IGN);
	pid = fork();
	envp = NULL;
	mini_assert(pid != ERROR, \
		MASSERT "(pid != ERROR), " \
		BINARY_INTERNAL MCOMMAND_1_FILE "line 106.");
	if (!pid)
	{
		set_signal(SIG_DFL, SIG_DFL);
		configure(&envp, envmap->root);
		if (*command == '.')
			path = resolve(command, envmap);
		else if (*command == '/')
			path = command;
		else
			path = find(command, envmap);
		execve(path, args, envp);
		finish(path, true);
	}
	return (pid);
}

/*
** exec_binary ()		- Execute Function on Binary
**
** return				- Exit Code
** command				- Command to Execute
** args					- All Arguments to Execute the Command
** envmap				- Variable for Maps the Environment Variables
** pid					- ID of Child Process
** ret					- Exit Code
** status				- Status of Child Process to Get Exit Code
*/

static inline int	exec_binary(char *command, char **args, t_rb *envmap)
{
	pid_t	pid;
	int		ret;
	int		status;

	pid = binary_internal(command, args, envmap);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		ret = WEXITSTATUS(status);
	else
	{
		ret = WTERMSIG(status);
		if (ret == SIGQUIT)
			jputendl("Quit: 3", STDERR_FILENO);
		else
			jputendl("", STDERR_FILENO);
		ret = SIGOFFSET + ret;
	}
	return (ret);
}

/*
** exec_cmd ()			- Execute Function on Syntax Command
**
** return				- void
** syntax				- Specific Syntax Node
** envmap				- Variable for Maps the Environment Variables
** i					- Index to Iterate All Elements
** ret					- Exit Code to Register
** args					- All Arguments to Execute the Command
*/

void	exec_cmd(t_as *syntax, t_rb *envmap)
{
	int		i;
	int		ret;
	char	**args;

	i = -1;
	arrange(syntax->token);
	args = capture(syntax);
	while (args[++i] != NULL)
		arrange(args[i]);
	if (is_builtin(syntax))
		ret = exec_builtin(syntax->token, args, envmap);
	else
		ret = exec_binary(syntax->token, args, envmap);
	rb_insert(envmap, jstrdup("?"), jitoa(ret));
	set_signal(customized, SIG_IGN);
	delete(&args);
}
