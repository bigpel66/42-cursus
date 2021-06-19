/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yield.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 18:06:23 by jseo              #+#    #+#             */
/*   Updated: 2021/06/19 21:21:38 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static bool	sorted(t_ps **ps)
{
	int		i;
	t_list	*lst;

	i = -1;
	lst = (*ps)->ah;
	while (++i < (*ps)->al - 1)
	{
		if (lst->v > lst->n->v)
			return (false);
		lst = lst->n;
	}
	return (true);
}

static void	simulate(t_ps **ps, char *line)
{
	size_t	len;

	len = jstrlen(line);
	if (line[0] == 'p')
		do_push(ps, line, len);
	else if (line[0] == 'r' && len == 2)
		do_rotate(ps, line, len);
	else if (line[0] == 'r' && len == 3)
		do_rrotate(ps, line, len);
	else if (line[0] == 's')
		do_swap(ps, line, len);
}

bool		yield(t_ps **ps, bool debug)
{
	int		ret;
	char	*line;

	(*ps)->al = jlstsize((*ps)->ah);
	if (!(*ps)->al)
		return (true);
	while (true)
	{
		if (debug)
			print_stacks(ps);
		ret = jgnl(STDIN_FILENO, &line);
		if (ret == ERROR)
			return (false);
		simulate(ps, line);
		jfree((void **)(&line));
		if (!ret)
			break ;
	}
	if (!sorted(ps))
		return (false);
	return (true);
}
