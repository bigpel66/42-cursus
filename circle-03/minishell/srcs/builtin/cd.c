/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:16:30 by jseo              #+#    #+#             */
/*   Updated: 2021/12/28 22:51:41 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** rollback ()			- Free Variables and Exit Cd
**
** return				- Exit Code (Such as Value from Exec Function)
** oldpath				- Path before Change Directory
** newpath				- Path after Change Directory
** ret					- Return Value When Fucntion Terminated
*/

static inline int	rollback(char *oldpath, char *newpath, int ret)
{
	jfree((void **)(&oldpath));
	jfree((void **)(&newpath));
	return (ret);
}

/*
** builtin_cd ()		- Cd Command in Shell
**
** return				- Exit Code (Such as Value from Exec Function)
** args					- Arguments to Use for Cd
** envmap				- Variable for Maps the Environment Variables
** ret					- Return Value after Calling chdir Function
** oldpath				- Path before Change Directory
** newpath				- Path after Change Directory
*/

int		builtin_cd(char **args, t_rb *envmap)
{
	int		ret;
	char	*oldpath;
	char	*newpath;

	if (*(args + 1) == NULL)
		newpath = jstrdup(get_value(envmap, "HOME"));
	else
		newpath = jstrdup(*(args + 1));
	oldpath = getcwd(NULL, 0);
	if (oldpath == NULL || newpath == NULL)
		return (rollback(oldpath, newpath, GENERAL));
	ret = chdir(newpath);
	if (ret < 0)
	{
		jputstr("cd: ", STDERR_FILENO);
		jputstr(newpath, STDERR_FILENO);
		jputendl(": No such file or directory", STDERR_FILENO);
		return (rollback(oldpath, newpath, GENERAL));
	}
	jfree((void **)(&newpath));
	rb_insert(envmap, jstrdup("OLDPWD"), oldpath);
	rb_insert(envmap, jstrdup("PWD"), getcwd(NULL, 0));
	return (VALID);
}
