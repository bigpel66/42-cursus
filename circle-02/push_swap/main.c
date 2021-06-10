/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:01:05 by jseo              #+#    #+#             */
/*   Updated: 2021/06/10 14:19:26 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	free_mo(t_mo **s)
{
	jlstclear(&((*s)->a));
	jlstclear(&((*s)->b));
	jlstclear(&((*s)->i));
	jlstclear(&((*s)->t));
	jfree((void **)(s));
}

t_list	**args_parse(char *argv, t_list **lst, int *cnt)
{
	int		v;
	t_list	**prv;

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

bool	args_check(int argc, char **argv, t_mo **s)
{
	int		i;
	t_list	**lst;
	t_list	**prv;
	t_list	**end;

	if (argc == 1)
		return (false);
	i = 0;
	lst = &((*s)->a);
	prv = NULL;
	while (++i < argc)
	{
		end = args_parse(argv[i], lst, &((*s)->cnt));
		if (prv)
			(*lst)->p = *prv;
		if (!end)
		{
			free_mo(s);
			return (false);
		}
		lst = &((*end)->n);
		prv = end;
	}
	return (true);
}

int		main(int argc, char **argv)
{
	t_mo	*s;

	if (!jcalloc((void **)(&s), 1, sizeof(t_mo)) || !args_check(argc, argv, &s))
	{
		jputstr("Error\n", STDERR_FILENO);
		return (INVALID);
	}
	// dup check
	// instruction_generate();
	// instruction_optimize();
	free_mo(&s);
	return (VALID);
}
