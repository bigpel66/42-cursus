/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:01:05 by jseo              #+#    #+#             */
/*   Updated: 2021/06/09 15:50:42 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**args_parse(char *argv, t_list **lst)
{
	t_list	*tmp;

	// parse argv
	// make it integer
	// lst generate and alloc integer
	if (something)
			return (NULL);
}

t_bool	args_check(int argc, char **argv, t_list **lst)
{
	int		i;
	t_list	**end;

	if (argc == 1)
		return (FALSE);
	i = 0;
	while (++i < argc)
	{
		end = args_parse(argv[i], lst);
		if (!end)
		{
			jlstclear(lst);
			return (FALSE);
		}
		lst = &((*end)->p);
	}
	return (TRUE);
}

int		main(int argc, char **argv)
{
	t_list	*lst;

	if (!args_check(argc, argv, &lst))
	{
		jputstr("Error\n", STDERR_FILENO);
		return (INVALID);
	}
	// instruction_generate();
	// instruction_optimize();
	return (VALID);
}
