/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:01:05 by jseo              #+#    #+#             */
/*   Updated: 2021/06/17 15:50:48 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** This is the instruction test
** Paste one of those into the "else" phrase
**
** test_push(&ps);
** test_rotate(&ps);
** test_rrotate(&ps);
** test_swap(&ps);
*/

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
			return (NULL);
		if (prv)
			(*lst)->p = *prv;
		prv = lst;
		lst = &((*lst)->n);
	}
	return (prv);
}

static bool		check(int ac, char **av, t_ps **ps)
{
	int		i;
	t_list	**lst;
	t_list	**prv;
	t_list	**end;

	i = 0;
	lst = &((*ps)->ah);
	prv = NULL;
	while (++i < ac)
	{
		end = parse(av[i], &((*ps)->s), lst);
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

int				main(int ac, char **av)
{
	t_ps	*ps;

	ps = NULL;
	if (ac == 1)
		exit_valid(&ps);
	if (!(jcalloc((void **)(&ps), 1, sizeof(t_ps)) && check(ac, av, &ps)))
		exit_invalid(&ps);
	yield(&ps);
	exit_valid(&ps);
}
