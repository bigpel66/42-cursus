/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:32:46 by jseo              #+#    #+#             */
/*   Updated: 2021/12/30 17:21:51 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_rdr_gt(t_as *syntax)
{
	(void)syntax;
}

void	exec_rdr_lt(t_as *syntax)
{
	(void)syntax;
}

void	exec_rdr_rshift(t_as *syntax)
{
	(void)syntax;
}

void	exec_rdr_lshift(t_as *syntax, t_rb *envmap)
{
	(void)syntax;
	(void)envmap;
}

void	exec_rdr(t_as *syntax, t_rb *envmap)
{
	if (!jstrncmp(syntax->token, ">", BUFFER_SIZE))
		exec_rdr_gt(syntax);
	else if (!jstrncmp(syntax->token, "<", BUFFER_SIZE))
		exec_rdr_lt(syntax);
	else if (!jstrncmp(syntax->token, ">>", BUFFER_SIZE))
		exec_rdr_rshift(syntax);
	else if (!jstrncmp(syntax->token, "<<", BUFFER_SIZE))
		exec_rdr_lshift(syntax, envmap);
	if (syntax->right != NULL)
		syntax->right->exec(syntax->right, envmap);
}
