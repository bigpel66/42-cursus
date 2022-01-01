/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:05:13 by jseo              #+#    #+#             */
/*   Updated: 2022/01/02 01:17:14 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	configure(char ***envp, t_rb *envmap)
{
	(void)envp;
	(void)envmap;
}

char	*find(char *command, t_rb *envmap)
{
	(void)command;
	(void)envmap;
	return (NULL);
}

char	*resolve(char *command, t_rb *envmap)
{
	int		ret;
	char	*sep;
	char	*path;

	sep = command;
	while (jstrchr(sep + 1, '/') != NULL)
		sep = jstrchr(sep + 1, '/');
	*sep = '\0';
	ret = chdir(command);
	*sep = '/';
	if (ret < 0)
	{
		errno = ENOENT;
		finish(command, true);
	}
	path = getcwd(NULL, 0);
	chdir(get_value(envmap, "PWD"));
	return (jstrjoin(path, sep));
}
