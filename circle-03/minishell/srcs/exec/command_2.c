/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 17:25:29 by jseo              #+#    #+#             */
/*   Updated: 2022/01/02 11:20:19 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** stretch ()			- Stretch the char ** Type Data
**
** return				- Resized char ** Type Data
** args					- All Arguments to be Copied
** size					- Current Size of char ** Type Data
** i					- Index to Iterate All Elements
** res					- All Arguments to be Resized
*/

static inline char	**stretch(char **args, size_t size)
{
	int		i;
	char	**res;

	i = -1;
	jcalloc((void **)(&res), size + 1, sizeof(char *));
	mini_assert(res != NULL, \
		MASSERT "(res != NULL), " STRETCH MCOMMAND_2_FILE "line 32.");
	while (args[++i] != NULL)
	{
		res[i] = jstrdup(args[i]);
		mini_assert(res[i] != NULL, \
			MASSERT "(res[i] != NULL), " \
			STRETCH MCOMMAND_2_FILE "line 37.");
	}
	delete(&args);
	return (res);
}

/*
** accumulate ()		- Accumulate the Chunk to the char ** Type Data
**
** return				- void
** size					- Current Size of char ** Type Data
*/

static inline void	accumulate(char ***args, char *chunk)
{
	size_t	size;

	size = 0;
	if (*args == NULL)
	{
		jcalloc((void **)(args), 2, sizeof(char *));
		mini_assert(*args != NULL, \
			MASSERT "(*args != NULL), " \
			ACCUMULATE MCOMMAND_2_FILE "line 60.");
		**args = jstrdup(chunk);
		mini_assert(**args != NULL, \
			MASSERT "(**args != NULL), " \
			ACCUMULATE MCOMMAND_2_FILE "line 64.");
	}
	else
	{
		while ((*args)[size] != NULL)
			++size;
		*args = stretch(*args, size + 1);
		(*args)[size] = jstrdup(chunk);
		mini_assert((*args)[size] != NULL, \
			MASSERT "((*args)[size] != NULL), " \
			ACCUMULATE MCOMMAND_2_FILE "line 74.");
	}
}

/*
** capture ()			- Capture the Arguments
**
** return				- All Arguments to Execute the Command
** syntax				- Specific Syntax Node
** args					- All Arguments to Execute the Command
** search				- Search the Child of the Specific Syntax Node
*/

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

/*
** configure ()			- Configure the Environmente Variables
**
** return				- void
** envp					- Environment Variables to Execute the Command
** node					- Specific Node
** entry				- Entry to be Appended
*/

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

/*
** delete ()			- Free the char ** Type Data
**
** return				- void
** i					- Index to Iterate All Elements
*/

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
