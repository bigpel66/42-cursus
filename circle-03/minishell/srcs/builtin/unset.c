/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:16:40 by jseo              #+#    #+#             */
/*   Updated: 2022/01/02 18:47:05 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** builtin_unset ()		- Unset Command in Shell
**
** return				- Exit Code (Such as Value from Exec Function)
** args					- Arguments to Use for Unset
** envmap				- Variable for Maps the Environment Variables
** ret					- Exit Code
*/

int	builtin_unset(char **args, t_rb *envmap)
{
	t_exit	ret;

	ret = VALID;
	if (*(args + 1) == NULL)
		return (ret);
	while (*(++args) != NULL)
	{
		if (!jisalpha(**args))
		{
			ret = BUILTIN;
			jputstr("unset: `", STDERR_FILENO);
			jputstr(*args, STDERR_FILENO);
			jputendl("': " IDENTIFIER, STDERR_FILENO);
		}
		else
			rb_delete(envmap, *args);
	}
	return (ret);
}
