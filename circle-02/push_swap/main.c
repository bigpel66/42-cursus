/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:01:05 by jseo              #+#    #+#             */
/*   Updated: 2021/06/10 15:55:48 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	free_mo(t_mo **s)
{
	if (!*s)
		return ;
	jlstclear(&((*s)->a));
	jlstclear(&((*s)->b));
	// free rb
	jfree((void **)(s));
}

t_list	**args_parse(char *argv, t_list **lst, int *cnt)
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

bool	args_check(int argc, char **argv, t_mo **s)
{
	int		i;
	t_list	**lst;
	t_list	**end;

	if (argc == 1)
		return (false);
	i = 0;
	lst = &((*s)->a);
	while (++i < argc)
	{
		end = args_parse(argv[i], lst, &((*s)->cnt));
		if (!end)
		{
			free_mo(s);
			return (false);
		}
		lst = &((*end)->n);
	}
	return (true);
}

bool	rb_search(t_node **r, int v)
{
	t_node	*n;

	n = *r;
	while (n)
	{
		if (v < n->v)
			n = n->l;
		else if (v > n->v)
			n = n->r;
		else
			return (true);
	}
	return (false);
}

void	rb_alloc_root(t_node **r, t_node **n)
{
	(*n)->c = 'b';
	*r = *n;
}

void	rb_left_rotate(t_node **r, t_node **n)
{
	t_node **
}

void	rb_right_rotate(t_node **r, t_node **n)
{
}

void	rb_fix_color(t_node **r, t_node **n)
{
	while (*n != *r && (*n)->p->c == 'r')
	{
	}
	(*r)->c = 'b';
}

void	rb_alloc_rest(t_node **r, t_node **n)
{
	t_node	*p;
	t_node	*c;

	p = NULL;
	c = *r;
	while (c)
	{
		p = c;
		if ((*n)->v < c->v)
			c = c->l;
		else
			c = c->r;
	}
	(*n)->p = p;
	if ((*n)->v < p->v)
		p->l = *n;
	else
		p->r = *n;
	rb_fix_color(r, n);
}

bool	rb_insert(t_node **r, int v)
{
	t_node	*n;

	if (rb_search(r, v) || !jnodenew(&n, v))
		return (false);
	if (!*r)
		rb_alloc_root(r, &n);
	else
		rb_alloc_rest(r, &n);
	return (true);
}

bool	args_unique(t_mo **s)
{
	t_list	*tmp;

	tmp = (*s)->a;
	while (tmp)
	{
		if (!rb_insert(&((*s)->r), tmp->v))
			return (false);
		tmp = tmp->n;
	}
	return (true);
}

int		main(int argc, char **argv)
{
	bool	e;
	t_mo	*s;

	e = false;
	s = NULL;
	if (!jcalloc((void **)(&s), 1, sizeof(t_mo))
			|| !args_check(argc, argv, &s)
			|| !args_unique(&s))
		e = true;
	else
	{
		// make optimize preset
		// instruction_generate();
		// instruction_optimize();
	}
	free_mo(&s);
	if (e)
	{
		jputstr("Error\n", STDERR_FILENO);
		return (INVALID);
	}
	return (VALID);
}
