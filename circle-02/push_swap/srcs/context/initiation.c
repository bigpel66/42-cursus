/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:36:07 by jseo              #+#    #+#             */
/*   Updated: 2021/06/18 16:07:02 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	**parse(char *av, t_set **set, t_list **lst)
{
	int		v;
	t_list	**prv;

	prv = NULL;
	jstrtrim(&av);
	while (*av)
	{
		v = 0;
		if (!(jatoi(&av, &v) && set_insert(set, v) && jlstnew(lst, v)))
		{
			set_delete(set);
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

bool			check(int ac, char **av, t_ps **ps, t_set **set)
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
		end = parse(av[i], set, lst);
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
	value(set, ps);
	set_delete(set);
	return (true);
}

void			prerequisite(t_ps **ps, t_base *base)
{
	(*ps)->al = jlstsize((*ps)->ah);
	stack_series(ps, base);
	stack_correction(ps, (base->f_index + 1) % (*ps)->al);
	stack_series(ps, base);
}
