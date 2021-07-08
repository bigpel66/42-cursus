/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:43:20 by jseo              #+#    #+#             */
/*   Updated: 2021/07/08 17:24:23 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_invalid(t_arg *x, bool custom, const char *s1, const char *s2)
{
	if (custom)
	{
		write(STDERR_FILENO, s1, jstrlen(s1));
		write(STDERR_FILENO, s2, jstrlen(s2));
		if (*s1)
			write(STDERR_FILENO, "\n", 1);
	}
	else
		strerror(errno);
	free_arg(x);
	exit(INVALID);
}

void	exit_valid(t_arg *x)
{
	free_arg(x);
	exit(VALID);
}
