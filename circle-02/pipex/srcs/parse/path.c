/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:40:25 by jseo              #+#    #+#             */
/*   Updated: 2021/07/09 15:49:48 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static bool	delimiter(int c)
{
	return (c == ':');
}

bool	path(char **envp, t_arg *x)
{
	char	*path;

	while (*envp && jstrncmp(*envp, "PATH", 4))
		++envp;
	if (!(*envp))
		return (false);
	path = *envp;
	x->path = jsplit(path + 5, delimiter);
	if (!(x->path))
		return (false);
	return (true);
}
