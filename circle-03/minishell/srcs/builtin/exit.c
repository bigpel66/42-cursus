/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:16:35 by jseo              #+#    #+#             */
/*   Updated: 2022/01/01 12:37:58 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** builtin_exit ()		- Exit Command in Shell
**
** return				- Exit Code (Such as Value from Exec Function)
** args					- Arguments to Use for Exit
** ret					- Exit Code of Ascii to Int
** valid				- Whether Valid or Not to Exit
** search				- To Find Exit Code Well Formed with Digits
*/

int	builtin_exit(char **args)
{
	int		ret;
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
		jputendl(": numeric argument required", STDERR_FILENO);
		exit(RANGE);
	}
	else if (valid && *(args + 1) != NULL && *(args + 2) != NULL)
	{
		jputendl("exit\nexit: too many arguments", STDERR_FILENO);
		return (GENERAL);
	}
	jputendl("exit", STDOUT_FILENO);
	jatoi(&(*(args + 1)), &ret);
	exit(ret);
}
