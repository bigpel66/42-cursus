/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:01:05 by jseo              #+#    #+#             */
/*   Updated: 2021/06/11 10:52:36 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void free_ps(t_ps **ps)
{
	if (!*ps)
		return;
	jlstclear(&((*ps)->ah));
	jlstclear(&((*ps)->bh));
	set_delete(&((*ps)->s));
	map_delete(&((*ps)->m));
	jfree((void **)(ps));
}

static t_list **args_parse(char *argv, t_list **lst, int *cnt)
{
	int v;
	t_list **prv;

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

static bool args_check(int argc, char **argv, t_ps **ps)
{
	int i;
	t_list **lst;
	t_list **prv;
	t_list **end;

	if (argc == 1)
		return (false);
	i = 0;
	lst = &((*ps)->ah);
	prv = NULL;
	while (++i < argc)
	{
		end = args_parse(argv[i], lst, &((*ps)->cnt));
		if (!end)
		{
			free_ps(ps);
			return (false);
		}
		if (prv)
			(*lst)->p = *prv;
		prv = end;
		lst = &((*end)->n);
	}
	(*ps)->at = *end;
	return (true);
}

static bool args_unique(t_ps **ps)
{
	t_list *tmp;

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

static bool args_sorted(t_ps **ps)
{
	t_list *tmp;

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

int main(int argc, char **argv)
{
	bool e;
	t_ps *ps;

	e = false;
	ps = NULL;
	if (!jcalloc((void **)(&ps), 1, sizeof(t_ps)) ||
		!args_check(argc, argv, &ps) || !args_unique(&ps))
		e = true;
	else
	{
		if (!args_sorted(&ps))
		{
			// instruction_generate();
			// instruction_optimize();
		}
		else
		printf("sorted\n");
	}
	free_ps(&ps);
	if (e)
	{
		jputstr("Error\n", STDERR_FILENO);
		return (INVALID);
	}
	return (VALID);
}
