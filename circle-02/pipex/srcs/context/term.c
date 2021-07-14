/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:43:20 by jseo              #+#    #+#             */
/*   Updated: 2021/07/14 23:30:46 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_child(t_arg *x, int code, const char *s1, const char *s2)
{
	if (code)
		jerror(strerror(code), NULL);
	else
		jerror(s1, s2);
	free_arg(x);
	exit(INVALID);
}

void	exit_invalid(t_arg *x, bool custom, const char *s1, const char *s2)
{
	int		fd;

	if (x && x->out && access(x->out, F_OK) == ERROR)
	{
		fd = open(x->out, O_CREAT | O_WRONLY, 0644);
		if (fd != ERROR)
			close(fd);
	}
	if (custom)
		jerror(s1, s2);
	else
		jerror(strerror(errno), NULL);
	free_arg(x);
	exit(INVALID);
}

void	exit_valid(t_arg *x)
{
	free_arg(x);
	exit(VALID);
}
