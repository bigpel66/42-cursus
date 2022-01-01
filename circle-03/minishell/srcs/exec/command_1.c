/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:32:40 by jseo              #+#    #+#             */
/*   Updated: 2022/01/01 14:35:12 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static inline void	delete(char ***args)
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

static inline void	add(char ***args, char *chunk)
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

static inline char	**capture(t_as *syntax)
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

void	exec_cmd(t_as *syntax, t_rb *envmap)
{
	int		i;
	int		ret;
	char	**args;

	i = -1;
	args = capture(syntax);
	if (is_builtin(syntax))
		ret = exec_builtin(syntax->token, args, envmap);
	else
		ret = exec_binary(syntax->token, args, envmap);
	rb_insert(envmap, jstrdup("?"), jstrdup(jitoa(ret)));
	// signal
	// while (args[++i] != NULL)
	// 	printf("exec args %d : %s\n", i, args[i]);
	delete(&args);
}
