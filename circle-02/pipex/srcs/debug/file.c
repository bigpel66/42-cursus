/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:12:44 by jseo              #+#    #+#             */
/*   Updated: 2021/07/09 16:51:50 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_args(t_arg *x)
{
	int		i;

	if (x->heredoc)
	{
		jputstr("#\tlimiter\t------->\t", STDOUT_FILENO);
		jputendl(x->limiter, STDOUT_FILENO);
		jputendl("#", STDOUT_FILENO);
	}
	else
	{
		jputstr("#\tinfile\t------->\t", STDOUT_FILENO);
		jputendl(x->in, STDOUT_FILENO);
		jputendl("#", STDOUT_FILENO);
	}
	jputstr("#\toutfile\t------->\t", STDOUT_FILENO);
	jputendl(x->out, STDOUT_FILENO);
	jputendl("#", STDOUT_FILENO);
	jputendl("#\texecfile", STDOUT_FILENO);
	i = -1;
	while (x->file[++i])
	{
		jputstr("#\t\t------->\t", STDOUT_FILENO);
		jputendl(x->file[i], STDOUT_FILENO);
	}
	jputendl("#", STDOUT_FILENO);
}
