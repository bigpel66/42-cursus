/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:08:34 by jseo              #+#    #+#             */
/*   Updated: 2021/04/27 00:19:14 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	p_init(t_p *arg, void *t, void *p, t_mlx *m)
{
	arg->t = t;
	arg->p = p;
	arg->m = m;
}

void	p_update(t_p *arg, int i, int x, t_mux *l)
{
	arg->i = i;
	arg->x = x;
	arg->l = l;
}

void	*mlx_col_calc(void *p)
{
	int		s;
	int		y;
	t_p		*tmp;
	t_color	pixel_color;

	tmp = p;
	y = tmp->m->rt.r.h;
	while (--y >= 0)
	{
		c_init(&pixel_color, 0.0, 0.0, 0.0);
		s = -1;
		while (++s < tmp->m->rt.c[tmp->i].spp)
		{
			// ray needed calc ray by u and v
			pixel_color = c_accumulate(pixel_color, c_trace(tmp));
		}
		pixel_color = c_gamma_scale(pixel_color, tmp->m->rt.c[tmp->i].spp);
		c_write(pixel_color, tmp, y);
	}
	return (NULL);
}

void	*mlx_img_calc(void *p)
{
	int			i;
	pthread_t	*t;
	t_p			*x;
	t_mux		l;

	i = -1;
	if (pthread_mutex_init(&l, NULL))
		e_thread_exec((t_p *)p, NULL, NULL, NULL);
	if (!dalloc((void **)(&x), ((t_p *)p)->m->rt.r.w, sizeof(t_p)))
		e_thread_exec((t_p *)p, NULL, NULL, &l);
	if (!dalloc((void **)(&t), ((t_p *)p)->m->rt.r.w, sizeof(pthread_t)))
		e_thread_exec((t_p *)p, NULL, (void **)(&x), &l);
	while (++i < ((t_p *)p)->m->rt.r.w)
	{
		x[i].ancestor = p;
		p_init(&x[i], t, x, ((t_p *)p)->m);
		p_update(&x[i], ((t_p *)p)->i, i, &l);
		if (pthread_create(&t[i], NULL, mlx_col_calc, &x[i]))
			e_thread_exec((t_p *)p, (void **)(&t), (void **)(&x), &l);
	}
	while (i--)
		if (pthread_join(t[i], NULL))
			e_thread_exec((t_p *)p, (void **)(&t), (void **)(&x), &l);
	free_thread((void **)(&t), (void **)(&x), &l);
	return (NULL);
}

void	mlx_calc(t_mlx *m)
{
	int			i;
	pthread_t	*t;
	t_p			*p;

	i = -1;
	if (!dalloc((void **)(&p), m->rt.cnt.c, sizeof(t_p)))
		e_thread_alloc(NULL, NULL, m);
	if (!dalloc((void **)(&t), m->rt.cnt.c, sizeof(pthread_t)))
		e_thread_alloc(NULL, (void **)(&p), m);
	while (++i < m->rt.cnt.c)
	{
		cam_init(&(m->rt.c[i]), v_init(0, 1, 0), m->rt.r.ar, 10.0);
		p_init(&p[i], t, p, m);
		p_update(&p[i], i, -1, NULL);
		if (pthread_create(&t[i], NULL, mlx_img_calc, &p[i]))
			e_thread_open((void **)(&t), (void **)(&p), m);
	}
	while (i--)
		if (pthread_join(t[i], NULL))
			e_thread_join((void **)(&t), (void **)(&p), m);
	free_thread((void **)(&t), (void **)(&p), NULL);
}
