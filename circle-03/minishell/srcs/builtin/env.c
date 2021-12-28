/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:16:34 by jseo              #+#    #+#             */
/*   Updated: 2021/12/28 14:35:25 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** env ()				- Env Command in Shell
**
** return				- Exit Code (Such as Value from Exec Function)
** envmap				- Variable for Maps the Environment Variables
*/

int	env(t_rb *envmap)
{
	rb_order(envmap->root);
	return (VALID);
}
