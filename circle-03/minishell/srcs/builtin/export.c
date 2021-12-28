/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:16:37 by jseo              #+#    #+#             */
/*   Updated: 2021/12/28 16:17:21 by jseo             ###   ########.fr       */
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
	jputstr("declare -x ", STDOUT_FILENO);
	jputstr((char *)(node->key), STDOUT_FILENO);
	if (!*(char *)(node->value))
		return ;
	jputstr("=\"", STDOUT_FILENO);
	jputstr((char *)(node->value), STDOUT_FILENO);
	jputendl("\"", STDOUT_FILENO);
}

/*
** logic ()				- Export Logic
**
** return				- void
** args					- Arguments to Use for Export
** envmap				- Variable for Maps the Environment Variables
** search				- Position of a Equal Sign
*/

static inline void	logic(char *arg, t_rb *envmap)
{
	char	*search;

	search = jstrchr(arg, '=');
	if (search == NULL)
		rb_insert(envmap, jstrdup(arg), jstrdup(""));
	else
	{
		*search++ = '\0';
		rb_insert(envmap, jstrdup(arg), jstrdup(search));
	}
}

/*
** export ()			- Export Command in Shell
**
** return				- Exit Code (Such as Value from Exec Function)
** args					- Arguments to Use for Export
** envmap				- Variable for Maps the Environment Variables
** ret					- Exit Code
*/

int	export(char **args, t_rb *envmap)
{
	t_exit	ret;

	ret = VALID;
	if (*(args + 1) == NULL)
		print(envmap->root);
	else
	{
		while (*(++args) != NULL)
		{
			if (!jisalpha(**args))
			{
				ret = GENERAL;
				jputstr("export: `", STDOUT_FILENO);
				jputstr(*args, STDOUT_FILENO);
				jputendl("': not a valid identifier", STDOUT_FILENO);
			}
			else
				logic(*args, envmap);
		}
	}
	return (ret);
}
