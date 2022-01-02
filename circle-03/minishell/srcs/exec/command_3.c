/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:05:19 by jseo              #+#    #+#             */
/*   Updated: 2022/01/02 09:13:40 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	arrange(char *chunk)
{
	size_t		*ict;

	jcalloc((void **)(&ict), 3, sizeof(size_t));
	mini_assert(ict != NULL, \
		MASSERT "line .");
	while (ict[INDEX] < jstrlen(chunk))
	{
		if (chunk[ict[INDEX]] == '\'' && ict[TYPE] == OFF)
			ict[TYPE] = SINGLE;
		else if (chunk[ict[INDEX]] == '\'' && ict[TYPE] == SINGLE)
			ict[TYPE] = OFF;
		else if (chunk[ict[INDEX]] == '\"' && ict[TYPE] == OFF)
			ict[TYPE] = DOUBLE;
		else if (chunk[ict[INDEX]] == '\"' && ict[TYPE] == DOUBLE)
			ict[TYPE] = OFF;
		else if (chunk[ict[INDEX]] != '\'' && chunk[ict[INDEX]] != '\"')
			chunk[ict[CONTENT]++] = chunk[ict[INDEX]];
		else if (chunk[ict[INDEX]] == '\"' && ict[TYPE] == SINGLE)
			chunk[ict[CONTENT]++] = '\"';
		else if (chunk[ict[INDEX]] == '\'' && ict[TYPE] == DOUBLE)
			chunk[ict[CONTENT]++] = '\'';
		++ict[INDEX];
	}
	chunk[ict[CONTENT]] = '\0';
	jfree((void **)(&ict));
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
