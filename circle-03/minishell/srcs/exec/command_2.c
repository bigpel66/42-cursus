/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:05:19 by jseo              #+#    #+#             */
/*   Updated: 2022/01/01 17:35:57 by jseo             ###   ########.fr       */
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

void	add(char ***args, char *chunk)
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

char	**capture(t_as *syntax)
{
	char	**args;
	t_as	*search;

	args = NULL;
	add(&args, syntax->token);
	search = syntax->right;
	while (search != NULL)
	{
		add(&args, search->token);
		search = search->right;
	}
	return (args);
}

void	delete(char ***args)
{
	int		i;

	if (*args == NULL)
		return ;
	i = -1;
	while ((*args)[++i] != NULL)
		jfree((void **)(&((*args)[i])));
	jfree((void **)(&((*args)[i])));
	jfree((void **)(&(*args)));
}
