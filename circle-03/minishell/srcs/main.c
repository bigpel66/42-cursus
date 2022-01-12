/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:41:44 by jseo              #+#    #+#             */
/*   Updated: 2022/01/12 15:34:48 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** art ()				- Print Ascii Art before Launch Main Loop
**
** return				- void
** fd					- File Descriptor to Print
** line					- Content of the File Separated by Newline
*/

static inline void	art(void)
{
	int		fd;
	char	*line;

	fd = open("jseohyson.txt", O_RDONLY);
	while (jgnl(fd, &line) >= SUCCESS)
	{
		jputendl(line, STDERR_FILENO);
		jfree((void **)(&line));
	}
	jfree((void **)(&line));
}

/*
** main ()				- Entry Function of Minishell
**
** return				- Status Code of Exiting Minishell
** argc					- The Number of Argument
** argv					- The Actual Arguments
** envp					- The Environment Variables on the Entry Time
** input				- Variable for a User Input
** chunks				- Variable for Tokens of User Input
** syntax				- Variable for a Syntax Tree from Chunks
** envmap				- Variable for Maps the Environment Variables
*/

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_lst	*chunks;
	t_as	*syntax;
	t_rb	*envmap;

	input = NULL;
	chunks = NULL;
	syntax = NULL;
	art();
	envmap = rb_init(rb_compare);
	set_signal(customized, SIG_IGN);
	echoctl_off();
	pair(argc, argv, envp, envmap);
	loop(input, chunks, syntax, envmap);
	return (VALID);
}
