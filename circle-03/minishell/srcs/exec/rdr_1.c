/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdr_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:32:46 by jseo              #+#    #+#             */
/*   Updated: 2022/01/04 17:32:49 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** exec_rdr ()			- Execute Function on Syntax Redirection
**
** return				- void
** syntax				- Specific Syntax Node
** envmap				- Variable for Maps the Environment Variables
** cont					- Continue to Execute or Not
*/

void	exec_rdr(t_as *syntax, t_rb *envmap)
{
	bool	cont;

	cont = true;
	if (!jstrncmp(syntax->token, ">", BUFFER_SIZE))
		exec_rdr_gt(syntax);
	else if (!jstrncmp(syntax->token, "<", BUFFER_SIZE))
		cont = exec_rdr_lt(syntax, envmap);
	else if (!jstrncmp(syntax->token, ">>", BUFFER_SIZE))
		exec_rdr_rshift(syntax);
	else if (!jstrncmp(syntax->token, "<<", BUFFER_SIZE))
		exec_rdr_lshift(syntax, envmap);
	if (cont && syntax->right != NULL)
		syntax->right->exec(syntax->right, envmap);
}
