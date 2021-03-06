/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:52:13 by jseo              #+#    #+#             */
/*   Updated: 2021/07/10 12:51:51 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	s_quote(int c)
{
	return (c == '\'');
}

bool	d_quote(int c)
{
	return (c == '\"');
}

bool	es_quote(int c1, int c2)
{
	return (c1 == '\\' && c2 == '\'');
}

bool	ed_quote(int c1, int c2)
{
	return (c1 == '\\' && c2 == '\"');
}
