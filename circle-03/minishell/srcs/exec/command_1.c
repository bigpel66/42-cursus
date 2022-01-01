/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:32:40 by jseo              #+#    #+#             */
/*   Updated: 2022/01/02 02:06:23 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static inline bool	is_builtin(t_as *syntax)
{
	int		i;
	char	*lower;
	bool	builtin;

	i = -1;
	lower = jstrdup(syntax->token);
	builtin = false;
	mini_assert(lower != NULL, \
		MASSERT "line .");
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

static inline int		exec_builtin(char *command, char **args, t_rb *envmap)
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

static inline pid_t	binary_internal(char *command, char **args, t_rb *envmap)
{
	pid_t	pid;
	char	*path;
	char	**envp;

	set_signal(SIG_IGN, SIG_IGN);
	pid = fork();
	envp = NULL;
	mini_assert(pid != ERROR, \
		MASSERT "(pid != ERROR), " "line .");
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

static inline int		exec_binary(char *command, char **args, t_rb *envmap)
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
	rb_insert(envmap, jstrdup("?"), jstrdup(jitoa(ret)));
	set_signal(customized, SIG_IGN);
	delete(&args);
}
