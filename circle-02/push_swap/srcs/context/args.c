/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 16:45:18 by jseo              #+#    #+#             */
/*   Updated: 2021/06/15 19:53:21 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	**parse(char *argv, t_set **s, t_list **lst, int *cnt)
{
	int		v;
	t_list	**prv;

	prv = NULL;
	jstrtrim(&argv);
	while (*argv)
	{
		v = 0;
		++(*cnt);
		if (!(jatoi(&argv, &v) && set_insert(s, v) && jlstnew(lst, v)))
			return (NULL);
		if (prv)
			(*lst)->p = *prv;
		prv = lst;
		lst = &((*lst)->n);
	}
	return (prv);
}

bool			check(int argc, char **argv, t_ps **ps)
{
	int		i;
	t_list	**lst;
	t_list	**prv;
	t_list	**end;

	if (argc == 1)
		return (false);
	i = 0;
	lst = &((*ps)->ah);
	prv = NULL;
	while (++i < argc)
	{
		end = parse(argv[i], &((*ps)->s), lst, &((*ps)->e));
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
	return (true);
}

bool			sorted(t_ps **ps)
{
	t_list	*c1;
	t_list	*c2;

	c1 = (*ps)->ah;
	c2 = (*ps)->ah->n;
	if (c1 == c2)
		return (true);
	while (true)
	{
		if (c2 == (*ps)->ah)
			return (true);
		if (c1->v > c2->v)
			return (false);
		c1 = c1->n;
		c2 = c2->n;
	}
}
