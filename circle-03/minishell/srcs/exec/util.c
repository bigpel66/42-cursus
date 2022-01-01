/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 17:25:29 by jseo              #+#    #+#             */
/*   Updated: 2022/01/01 23:13:43 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static inline char	**stretch(char **args, size_t size)
{
	int		i;
	char	**res;

	i = -1;
	jcalloc((void **)(&res), size + 1, sizeof(char *));
	mini_assert(res != NULL, \
		MASSERT "line .");
	while (args[++i] != NULL)
	{
		res[i] = jstrdup(args[i]);
		mini_assert(res[i] != NULL, \
			MASSERT "line .");
	}
	delete(&args);
	return (res);
}

void	accumulate(char ***args, char *chunk)
{
	size_t	size;

	size = 0;
	if (*args == NULL)
	{
		jcalloc((void **)(args), 2, sizeof(char *));
		mini_assert(*args != NULL, \
			MASSERT "line .");
		**args = jstrdup(chunk);
		mini_assert(**args != NULL, \
			MASSERT "line .");
	}
	else
	{
		while ((*args)[size] != NULL)
			++size;
		*args = stretch(*args, size + 1);
		(*args)[size] = jstrdup(chunk);
		mini_assert((*args)[size] != NULL, \
				MASSERT "line .");
	}
}

void	finish(char *entry, bool shutdown)
{
	if (errno)
		jputstr(entry, STDERR_FILENO);
	if (errno == ENOENT)
	{
		jputendl(": No such file or directory", STDERR_FILENO);
		if (shutdown)
			exit(GENERAL);
	}
	if (errno == EFAULT)
	{
		jputendl(": Command not found", STDERR_FILENO);
		if (shutdown)
			exit(NOTFOUND);
	}
	if (errno == EACCES)
	{
		jputendl(": Permission denied", STDERR_FILENO);
		if (shutdown)
			exit(NOTEXECUTABLE);
	}
	if (shutdown)
		exit(VALID);
}
