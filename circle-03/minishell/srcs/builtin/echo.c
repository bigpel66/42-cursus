/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:16:33 by jseo              #+#    #+#             */
/*   Updated: 2021/12/28 14:30:18 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** echo ()				- Echo Command in Shell
**
** return				- Exit Code (Such as Value from Exec Function)
** args					- Arguments to Use for Echo
** option				- Echo has n Nption or Not
*/

int	echo(char **args)
{
	int		option;

	option = false;
	++args;
	if (*args == NULL)
	{
		jputchar('\n', STDOUT_FILENO);
		return (VALID);
	}
	if (!jstrncmp("-n", *args,  BUFFER_SIZE))
		++option;
	args += option;
	while (*args != NULL)
	{
		jputstr(*args, STDOUT_FILENO);
		if (*(args + 1) != NULL)
			jputchar(' ', STDOUT_FILENO);
		++args;
	}
	if (!option)
		jputchar('\n', STDOUT_FILENO);
	return (VALID);
}
