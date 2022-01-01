/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:05:19 by jseo              #+#    #+#             */
/*   Updated: 2022/01/01 14:35:34 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_builtin(t_as *syntax)
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

int		exec_builtin(char *command, char **args, t_rb *envmap)
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
		return (GENERAL);
}

int		exec_binary(char *command, char **args, t_rb *envmap)
{
	(void)command;
	(void)args;
	(void)envmap;
	return (0);
}
