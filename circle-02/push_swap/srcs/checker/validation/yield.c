/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yield.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 18:06:23 by jseo              #+#    #+#             */
/*   Updated: 2021/06/20 09:33:25 by jseo             ###   ########.fr       */
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

static bool	simulate(t_ps **ps, char *line)
{
	size_t	len;

	len = jstrlen(line);
	if (line[0] == 'p')
		return (do_push(ps, line, len));
	else if (line[0] == 'r' && len == 2)
		return (do_rotate(ps, line, len));
	else if (line[0] == 'r' && len == 3)
		return (do_rrotate(ps, line, len));
	else if (line[0] == 's')
		return (do_swap(ps, line, len));
	else if (line[0] == EOT)
		return (true);
	return (false);
}

void		yield(t_ps **ps, bool debug)
{
	int		ret;
	char	*line;

	(*ps)->al = jlstsize((*ps)->ah);
	if (!(*ps)->al)
		return ;
	while (true)
	{
		if (debug)
			print_stacks(ps);
		ret = jgnl(STDIN_FILENO, &line);
		if (ret == ERROR || !simulate(ps, line))
			exit_invalid(ps, "Error\n");
		jfree((void **)(&line));
		if (!ret)
			break ;
	}
	if (sorted(ps))
		jputstr("OK", STDOUT_FILENO);
	else
		jputstr("KO", STDOUT_FILENO);
}
