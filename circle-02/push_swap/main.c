/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:01:05 by jseo              #+#    #+#             */
/*   Updated: 2021/06/09 18:02:38 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**args_parse(char *argv, t_list **lst)
{
	int		v;
	t_list	*tmp;

	jstrtrim(&argv);
	while (*argv)
	{
		if (!jatoi(&argv, &v) || !jlstnew(lst, v))
			return (NULL);
		lst = &((*lst)->p);
	}
	return (lst);
}

bool	args_check(int argc, char **argv, t_list **lst)
{
	int		i;
	t_list	**end;

	if (argc == 1)
		return (false);
	i = 0;
	while (++i < argc)
	{
		end = args_parse(argv[i], lst);
		if (!end)
		{
			jlstclear(lst);
			return (false);
		}
		lst = &((*end)->p);
	}
	return (true);
}

int		main(int argc, char **argv)
{
	t_list	*lst;
	t_list	*bck;

	if (!args_check(argc, argv, &lst))
	{
		jputstr("Error\n", STDERR_FILENO);
		return (INVALID);
	}
	// instruction_generate();
	// instruction_optimize();
	jlstclear(&lst);	
	return (VALID);
}
