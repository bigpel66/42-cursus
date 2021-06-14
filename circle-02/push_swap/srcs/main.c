/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:01:05 by jseo              #+#    #+#             */
/*   Updated: 2021/06/14 12:48:16 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*
** This is the instruction test
** Paste one of those into the "else" phrase
**
** test_push(&ps);
** test_rotate(&ps);
** test_rrotate(&ps);
** test_swap(&ps);
*/

/*
static void	find_minimum(t_ps **ps)
{
	t_set	*s;

	s = (*ps)->s;
	while (s && s->l)
		s = s->l;
	(*ps)->min = s->v;
}

static void	find_maximum(t_ps **ps)
{
	t_set	*s;

	s = (*ps)->s;
	while (s && s->r)
		s = s->r;
	(*ps)->max = s->v;
}

int			main(int argc, char **argv)
{
	t_ps	*ps;
	bool	sorted;

	ps = NULL;
	sorted = true;
	if (!jcalloc((void **)(&ps), 1, sizeof(t_ps))
			|| !args_check(argc, argv, &ps)
			|| !args_unique(&ps, &sorted))
		exit_invalid(&ps);
	else
	{
		if (!sorted)
		{
			find_minimum(&ps);
			find_maximum(&ps);
			a_to_b(&ps, ps->cnt);
		}
	}
	exit_valid(&ps);
}
*/

bool m_value(t_set **m, int v)
{
	if ((*m) && (*m)->v == v)
		return (true);
	if ((*m) && (*m)->l)
		m_value(&((*m)->l), v);
	if ((*m) && (*m)->r)
		m_value(&((*m)->r), v);
	return (false);
}

bool	m_alloc(t_set **n, int o, int v)
{
	if (!jcalloc((void **)(n), 1, sizeof(t_set)))
		return (false);
	(*n)->o = o;
	(*n)->v = v;
	(*n)->l = NULL;
	(*n)->r = NULL;
	(*n)->p = NULL;
	return (true);
}

void	m_insert_root(t_set **m, t_set **n)
{
	(*n)->c = 'B';
	*m = *n;
}

void	m_insert_rest(t_set **m, t_set **n)
{
	t_set *i;
	t_set *t;

	i = NULL;
	t = (*m);
	while (t)
	{
		i = t;
		if ((*n)->o < t->o)
			t = t->l;
		else
			t = t->r;
	}
	(*n)->p = i;
	if ((*n)->o > i->o)
		i->r = (*n);
	else
		i->l = (*n);
}

void	m_left_rotate(t_set **m, t_set **n)
{
	t_set	*u;

	if (!(*n) || !(*n)->r)
		return ;
	u = (*n)->r;
	(*n)->r = u->l;
	if ((*n)->r)
		(*n)->r->p = (*n);
	u->p = (*n)->p;
	if (!((*n)->p))
		*m = u;
	else if ((*n) == (*n)->p->l)
		(*n)->p->l = u;
	else
		(*n)->p->r = u;
	u->l = (*n);
	(*n)->p = u;
}

void	m_right_rotate(t_set **m, t_set **n)
{
	t_set	*u;

	if (!(*n) || !(*n)->l)
		return ;
	u = (*n)->l;
	(*n)->l = u->r;
	if (u->r)
		u->r->p = (*n);
	u->p = (*n)->p;
	if (!(u->p))
		*m = u;
	else if ((*n) == (*n)->p->l)
		(*n)->p->l = u;
	else
		(*n)->p->r = u;
	u->r = (*n);
	(*n)->p = u;
}

void	m_red_color(t_set **n, t_set *u)
{
	u->c = 'B';
	(*n)->p->c = 'B';
	(*n)->p->p->c = 'R';
	(*n) = (*n)->p->p;
}

void	m_llb_color(t_set **m, t_set **n)
{
	char	c;

	c = '\0';
	if ((*n)->p == (*n)->p->p->l && (*n) == (*n)->p->l)
	{
		c = (*n)->p->c;
		(*n)->p->c = (*n)->p->p->c;
		(*n)->p->p->c = c;
		m_right_rotate(m, &((*n)->p->p));
	}
}

void	m_lrb_color(t_set **m, t_set **n)
{
	char	c;

	c = '\0';
	if ((*n)->p == (*n)->p->p->l && (*n) == (*n)->p->r)
	{
		c = (*n)->c;
		(*n)->c = (*n)->p->p->c;
		(*n)->p->p->c = c;
		m_left_rotate(m, &((*n)->p));
		m_right_rotate(m, &((*n)->p->p));
	}
}

void	m_rlb_color(t_set **m, t_set **n)
{
	char	c;

	c = '\0';
	if ((*n)->p == (*n)->p->p->r && (*n) == (*n)->p->l)
	{
		c = (*n)->c;
		(*n)->c = (*n)->p->p->c;
		(*n)->p->p->c = c;
		m_right_rotate(m, &((*n)->p));
		m_left_rotate(m, &((*n)->p->p));
	}
}

void	m_rrb_color(t_set **m, t_set **n)
{
	char	c;

	c = '\0';
	if ((*n)->p == (*n)->p->p->r && (*n) == (*n)->p->r)
	{
		c = (*n)->p->c;
		(*n)->p->c = (*n)->p->p->c;
		(*n)->p->p->c = c;
		m_left_rotate(m, &((*n)->p->p));
	}
}

void m_insert_fix(t_set **m, t_set **n)
{
	t_set	*u;

	while (*n != *m && *n != (*m)->l && *n != (*m)->r && (*n)->p->c == 'R')
	{
		u = NULL;
		if ((*n)->p && (*n)->p->p && (*n)->p == (*n)->p->p->l)
			u = (*n)->p->p->r;
		else if ((*n)->p && (*n)->p->p && (*n)->p == (*n)->p->p->r)
			u = (*n)->p->p->l;
		if (!u)
			(*n) = (*n)->p->p;
		else if (u->c == 'R')
			m_red_color(n, u);
		else
		{
			m_llb_color(m, n);
			m_lrb_color(m, n);
			m_rlb_color(m, n);
			m_rrb_color(m, n);
		}
	}
	(*m)->c = 'B';
}

bool m_insert(t_set **m, t_set **n)
{

	if (m_value(m, (*n)->v))
	{
		jputstr("dup\n", STDOUT_FILENO);
		jfree((void **)(n));
		return (false);
	}
	if (!(*m))
		m_insert_root(m, n);
	else
	{
		m_insert_rest(m, n);
		m_insert_fix(m, n);
	}
	return (true);
}

bool parse(t_m **m, char *argv)
{
	int v;
	t_set *n;
	jstrtrim(&argv);
	while (*argv)
	{
		v = 0;
		if (!jatoi(&argv, &v))
		{
			return (false);
		}
		if (!m_alloc(&n, ((*m)->cnt)++, v))
			{
						return (false);
			}
			if (!m_insert(&((*m)->a), &n))
			{
			return (false);
			}

	}
	return (true);
}

bool init(t_m **m, int argc, char **argv)
{
	int i;

	if (argc == 1)
		return (false);
	i = 0;
	while (++i < argc)
	{
		if (!parse(m, argv[i]))
			return (false);
	}
	return (true);
}

void	m_inorder(t_set **m)
{
	if (!*m)
		return ;
	m_inorder(&((*m)->l));
	jputnbr((*m)->v, STDOUT_FILENO);
	jputchar('\n', STDOUT_FILENO);
	m_inorder(&((*m)->r));
}


int main	(int argc, char **argv)
{
	t_m	*m;

	m = NULL;
	if (!(jcalloc((void **)(&m), 1, sizeof(t_m)) && init(&m, argc, argv)))
		return (1);
		// exit_invalid
		set_inorder(&(m->a));
	// else
}
