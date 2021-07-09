/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:32:01 by jseo              #+#    #+#             */
/*   Updated: 2021/07/09 16:54:42 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_vec(t_arg *x)
{
	int		i;
	int		j;

	jputendl("#\tARGS Vector", STDOUT_FILENO);
	i = -1;
	while (x->vec[++i])
	{
		jputstr("#\t\t------->", STDOUT_FILENO);
		j = -1;
		while (x->vec[i][++j])
		{
			jputstr("\t", STDOUT_FILENO);
			jputstr(x->vec[i][j], STDOUT_FILENO);
		}
		jputendl("", STDOUT_FILENO);
	}
}
