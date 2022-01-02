/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 17:25:29 by jseo              #+#    #+#             */
/*   Updated: 2022/01/02 09:12:58 by jseo             ###   ########.fr       */
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

static inline void	accumulate(char ***args, char *chunk)
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

char	**capture(t_as *syntax)
{
	char	**args;
	t_as	*search;

	args = NULL;
	accumulate(&args, syntax->token);
	search = syntax->right;
	while (search != NULL)
	{
		accumulate(&args, search->token);
		search = search->right;
	}
	return (args);
}

void	configure(char ***envp, t_node *node)
{
	char	*entry;

	if (node == NULL)
		return ;
	configure(envp, node->left);
	configure(envp, node->right);
	if (!jstrncmp((char *)(node->key), "#", BUFFER_SIZE) ||
		!jstrncmp((char *)(node->key), "*", BUFFER_SIZE) ||
		!jstrncmp((char *)(node->key), "?", BUFFER_SIZE))
		return ;
	if (!*((char *)(node->value)))
		return ;
	entry = jstrjoin((char *)(node->key), "=");
	jstrappend(&entry, (char *)(node->value));
	accumulate(envp, entry);
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
