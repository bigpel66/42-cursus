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

static void		free_ps(t_ps **ps)
{
	if (!*ps)
		return ;
	jlstclear(&((*ps)->a));
	jlstclear(&((*ps)->b));
	set_delete(&((*ps)->s));
	jfree((void **)(ps));
}

static t_list	**args_parse(char *argv, t_list **lst, int *cnt)
{
	int		v;
	t_list	**tmp;

	v = 0;
	tmp = NULL;
	jstrtrim(&argv);
	while (*argv)
	{
		++(*cnt);
		if (!jatoi(&argv, &v) || !jlstnew(lst, v))
			return (NULL);
		tmp = lst;
		lst = &((*lst)->n);
	}
	return (tmp);
}

static bool		args_check(int argc, char **argv, t_ps **ps)
{
	int		i;
	t_list	**lst;
	t_list	**end;

	if (argc == 1)
		return (false);
	i = 0;
	lst = &((*ps)->a);
	while (++i < argc)
	{
		end = args_parse(argv[i], lst, &((*ps)->cnt));
		if (!end)
		{
			free_ps(ps);
			return (false);
		}
		lst = &((*end)->n);
	}
	return (true);
}

static bool		args_unique(t_ps **ps)
{
	t_list	*tmp;

	tmp = (*ps)->a;
	while (tmp)
	{
		if (!set_insert(&((*ps)->s), tmp->v))
			return (false);
		tmp = tmp->n;
	}
	return (true);
}

int				main(int argc, char **argv)
{
	bool	e;
	t_ps	*ps;

	e = false;
	ps = NULL;
	if (!jcalloc((void **)(&ps), 1, sizeof(t_ps))
		|| !args_check(argc, argv, &ps)
		|| !args_unique(&ps))
		// || !inst_preset())
		e = true;
	else
	{
		set_inorder(&(ps->s));
		map_insert(&(ps->m), "abcd", "abcd");
		map_insert(&(ps->m), "ab", "ab");
		map_insert(&(ps->m), "a", "a");
		map_insert(&(ps->m), "ddd", "ddd");
		map_inorder(&(ps->m));
		// make optimize preset
		// instruction_generate();
		// instruction_optimize();
	}
	free_ps(&ps);
	if (e)
	{
		jputstr("Error\n", STDERR_FILENO);
		return (INVALID);
	}
	return (VALID);
}
