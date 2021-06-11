/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 16:45:18 by jseo              #+#    #+#             */
/*   Updated: 2021/06/11 16:45:19 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	**args_parse(char *argv, t_list **lst, int *cnt)
{
	int		v;
	t_list	**prv;

	v = 0;
	prv = NULL;
	jstrtrim(&argv);
	while (*argv)
	{
		++(*cnt);
		if (!jatoi(&argv, &v) || !jlstnew(lst, v))
			return (NULL);
		if (prv)
			(*lst)->p = *prv;
		prv = lst;
		lst = &((*lst)->n);
	}
	return (prv);
}

bool			args_check(int argc, char **argv, t_ps **ps)
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
		end = args_parse(argv[i], lst, &((*ps)->cnt));
		if (!end)
			return (false);
		if (prv)
			(*lst)->p = *prv;
		prv = end;
		lst = &((*end)->n);
	}
	(*ps)->at = *end;
	return (true);
}

bool			args_unique(t_ps **ps)
{
	t_list	*tmp;

	(*ps)->ah->p = (*ps)->at;
	(*ps)->at->n = (*ps)->ah;
	tmp = (*ps)->ah;
	while (true)
	{
		if (!set_insert(&((*ps)->s), tmp->v))
			return (false);
		tmp = tmp->n;
		if (tmp == (*ps)->ah)
			return (true);
	}
}

bool			args_sorted(t_ps **ps)
{
	t_list	*tmp;

	tmp = (*ps)->ah;
	while (true)
	{
		if (tmp->v > tmp->n->v)
			return (false);
		tmp = tmp->n;
		if (tmp == (*ps)->at)
			return (true);
	}
}
