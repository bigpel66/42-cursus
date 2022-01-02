/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:16:35 by jseo              #+#    #+#             */
/*   Updated: 2022/01/02 21:20:05 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** builtin_exit ()		- Exit Command in Shell
**
** return				- Exit Code (Such as Value from Exec Function)
** args					- Arguments to Use for Exit
** valid				- Whether Valid or Not to Exit
** search				- To Find Exit Code Well Formed with Digits
*/

int	builtin_exit(char **args)
{
	bool	valid;
	char	*search;

	valid = true;
	search = *(args + 1);
	while (search != NULL && *search)
		if (!jisdigit(*search++))
			valid = false;
	if (!valid)
	{
		jputstr("exit\nexit: ", STDERR_FILENO);
		jputstr(*(args + 1), STDERR_FILENO);
		jputendl(": " NUMERIC, STDERR_FILENO);
		exit(RANGE);
	}
	else if (valid && *(args + 1) != NULL && *(args + 2) != NULL)
	{
		jputendl("exit\nexit: " SEVERAL, STDERR_FILENO);
		return (BUILTIN);
	}
	jputendl("exit", STDOUT_FILENO);
	if (*(args + 1) == NULL)
		exit(VALID);
	exit(jatoi(*(args + 1)));
}
