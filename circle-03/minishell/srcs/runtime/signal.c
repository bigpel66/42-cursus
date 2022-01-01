/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:42:49 by jseo              #+#    #+#             */
/*   Updated: 2022/01/01 23:54:22 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** set_rl ()			- Setting on New Readline
**
** return				- Always True (Setting Well)
** out					- Out String before Reset
** fd					- File Descriptor for Out String
*/

bool	set_rl(char *out, int fd)
{
	if (out != NULL)
		jputstr(out, fd);
	jputendl("", fd);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	return (true);
}

/*
** customized ()		- Customized Signal Handler
**
** return				- void
** sig					- Signal Number
*/

void	customized(int sig)
{
	(void)sig;
	set_rl(NULL, STDOUT_FILENO);
}

/*
** set_signal ()		- Set SIGINT, SIGQUIT Actions
**
** return				- void
** action1				- SIGINT Handler
** action2				- SIGNQUIT Handler
*/

void	set_signal(void (*action1)(int), void (*action2)(int))
{
	signal(SIGINT, action1);
	signal(SIGQUIT, action2);
}
