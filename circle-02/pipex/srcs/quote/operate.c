/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 12:45:44 by jseo              #+#    #+#             */
/*   Updated: 2021/07/10 12:55:38 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	qequal(t_mode m1, t_mode m2)
{
	return (m1 == m2);
}

bool	qdiff(t_mode m1, t_mode m2)
{
	return (m1 != m2);
}

void	qshift(char **s, t_mode mode)
{
	if (mode == SQ || mode == DQ)
		++(*s);
	if (mode == ESQ || mode == EDQ)
		*s += 2;
}

t_mode	qcheck(int c1, int c2)
{
	if (jisspace(c1))
		return (BL);
	else if (s_quote(c1))
		return (SQ);
	else if (d_quote(c1))
		return (DQ);
	else if (es_quote(c1, c2))
		return (ESQ);
	else if (ed_quote(c1, c2))
		return (EDQ);
	else
		return (NAN);
}

void	qtrace(char **s, size_t *c, t_mode m1, bool (*f)(t_mode, t_mode))
{
	t_mode	m2;

	if (c && m1 != BL)
		++(*c);
	while (*(++(*s)))
	{
		m2 = qcheck(**s, *((*s) + 1));
		if (f(m1, m2))
			break ;
	}
}
