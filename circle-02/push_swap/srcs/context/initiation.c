/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:36:07 by jseo              #+#    #+#             */
/*   Updated: 2021/06/17 18:36:47 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	**parse(char *av, t_set **s, t_list **lst)
{
	int		v;
	t_list	**prv;

	prv = NULL;
	jstrtrim(&av);
	while (*av)
	{
		v = 0;
		if (!(jatoi(&av, &v) && set_insert(s, v) && jlstnew(lst, v)))
		{
			set_delete(s);
			return (NULL);
		}
		if (prv)
			(*lst)->p = *prv;
		prv = lst;
		lst = &((*lst)->n);
	}
	return (prv);
}

static void		value(t_set **s, t_ps **ps)
{
	t_set	*tmp;

	tmp = *s;
	while (tmp->l)
		tmp = tmp->l;
	(*ps)->min = tmp->v;
	tmp = *s;
	while (tmp->r)
		tmp = tmp->r;
	(*ps)->max = tmp->v;
}

bool			check(int ac, char **av, t_set **s, t_ps **ps)
{
	int		i;
	t_list	**prv;
	t_list	**lst;
	t_list	**end;

	i = 0;
	prv = NULL;
	lst = &((*ps)->ah);
	while (++i < ac)
	{
		end = parse(av[i], s, lst);
		if (!end)
			return (false);
		if (prv)
			(*lst)->p = *prv;
		prv = end;
		lst = &((*end)->n);
	}
	(*ps)->at = *end;
	(*end)->n = (*ps)->ah;
	(*ps)->ah->p = *end;
	value(s, ps);
	set_delete(s);
	return (true);
}

void			prerequisite(t_ps **ps)
{
	stack_len(ps);
	stack_series(ps);
	stack_correction(ps, ((*ps)->of_pos + 1) % (*ps)->al);
}
