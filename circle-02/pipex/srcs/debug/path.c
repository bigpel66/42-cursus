/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:28:21 by jseo              #+#    #+#             */
/*   Updated: 2021/07/09 16:52:03 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_path(t_arg *x)
{
	int		i;

	jputendl("#\t$PATH", STDOUT_FILENO);
	i = -1;
	while (x->path[++i])
	{
		jputstr("#\t\t------->\t", STDOUT_FILENO);
		jputendl(x->path[i], STDOUT_FILENO);
	}
	jputendl("#", STDOUT_FILENO);
}
