/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:26:59 by jseo              #+#    #+#             */
/*   Updated: 2021/07/09 16:45:10 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	debug(t_arg *x)
{
	jputstr("#========================================", STDOUT_FILENO);
	jputstr("\tDebug Mode\t", STDOUT_FILENO);
	jputendl("========================================#", STDOUT_FILENO);
	print_args(x);
	print_path(x);
	print_vec(x);
	jputstr("#========================================", STDOUT_FILENO);
	jputstr("======================", STDOUT_FILENO);
	jputendl("========================================#", STDOUT_FILENO);
}
