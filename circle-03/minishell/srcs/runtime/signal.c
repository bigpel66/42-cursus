/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:42:49 by jseo              #+#    #+#             */
/*   Updated: 2022/01/12 15:42:18 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** set_rl ()			- Setting on New Readline
**
** return				- Always True (Setting Well)
** in					- Input String to be Printed
** out					- Out String before Reset
** fd					- File Descriptor for Out String
** newline				- Print Newline or Not
*/

bool	set_rl(char *in, char *out, int fd, bool newline)
{
	if (in != NULL)
	{
		jputstr(in, fd);
		jputstr(": ", fd);
	}
	if (out != NULL)
		jputstr(out, fd);
	jputendl("", fd);
	if (newline)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
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
	set_rl(NULL, NULL, STDOUT_FILENO, true);
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
