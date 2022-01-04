/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:16:37 by jseo              #+#    #+#             */
/*   Updated: 2022/01/04 15:24:57 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** print ()				- Print All Exported Entries
**
** return				- void
** node					- Specific Node
*/

static inline void	print(t_node *node)
{
	if (node == NULL)
		return ;
	print(node->left);
	print(node->right);
	if (!jstrncmp((char *)(node->key), "#", BUFFER_SIZE) ||
		!jstrncmp((char *)(node->key), "*", BUFFER_SIZE) ||
		!jstrncmp((char *)(node->key), "?", BUFFER_SIZE))
		return ;
	jputstr("declare -x ", STDOUT_FILENO);
	jputstr((char *)(node->key), STDOUT_FILENO);
	if (!*(char *)(node->value))
	{
		jputendl("", STDOUT_FILENO);
		return ;
	}
	jputstr("=\"", STDOUT_FILENO);
	jputstr((char *)(node->value), STDOUT_FILENO);
	jputendl("\"", STDOUT_FILENO);
}

/*
** logic_internal ()	- Export Insert Logic
**
** return				- void
** search				- Position of a Equal Sign
** args					- Arguments to Use for Export
** envmap				- Variable for Maps the Environment Variables
*/

static inline void	logic_internal(char *search, char *arg, t_rb *envmap)
{
	*search++ = '\0';
	if (!jstrncmp(arg, "PS1", BUFFER_SIZE))
		rb_insert(envmap, jstrdup(arg), jstrjoin(search, " "));
	else
		rb_insert(envmap, jstrdup(arg), jstrdup(search));
}

/*
** logic ()				- Export Logic
**
** return				- void
** args					- Arguments to Use for Export
** envmap				- Variable for Maps the Environment Variables
** search				- Position of a Equal Sign
** value				- Value from the Specific Key on the Envmap
*/

static inline void	logic(char *arg, t_rb *envmap)
{
	char	*search;
	char	*value;

	search = jstrchr(arg, '=');
	if (search == NULL)
	{
		value = get_value(envmap, arg);
		if (!value)
			rb_insert(envmap, jstrdup(arg), jstrdup(""));
	}
	else if (*(search - 1) == '+')
	{
		*(search - 1) = '\0';
		*search++ = '\0';
		value = get_value(envmap, arg);
		if (value == NULL)
			value = "";
		rb_insert(envmap, jstrdup(arg), jstrjoin(value, search));
	}
	else
		logic_internal(search, arg, envmap);
}

/*
** valid ()				- Check the Argument Consists of Valid Identifiers
**
** return				- True or False
** search				- Position to Search Invalid Character
** i					- Index to Iterate All Elements
*/

static inline bool	valid(char *search)
{
	int		i;

	i = -1;
	while (search[++i])
	{
		if (search[i] == '=' || (search[i] == '+' && search[i + 1] == '='))
			return (true);
		if (!(search[i] == '_' || jisalpha(search[i]) || jisdigit(search[i])))
			return (false);
	}
	return (true);
}

/*
** builtin_export ()	- Export Command in Shell
**
** return				- Exit Code (Such as Value from Exec Function)
** args					- Arguments to Use for Export
** envmap				- Variable for Maps the Environment Variables
** ret					- Exit Code
*/

int	builtin_export(char **args, t_rb *envmap)
{
	t_exit	ret;

	ret = VALID;
	if (*(args + 1) == NULL)
		print(envmap->root);
	else
	{
		while (*(++args) != NULL)
		{
			if ((**args != '_' && !jisalpha(**args)) || !valid(*args))
			{
				ret = BUILTIN;
				jputstr("export: `", STDERR_FILENO);
				jputstr(*args, STDERR_FILENO);
				jputendl("': " IDENTIFIER, STDERR_FILENO);
			}
			else
				logic(*args, envmap);
		}
	}
	return (ret);
}
