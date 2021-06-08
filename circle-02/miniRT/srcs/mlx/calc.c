/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:08:34 by jseo              #+#    #+#             */
/*   Updated: 2021/05/07 17:46:02 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	mlx_write(t_color c, t_p *p, int x, int y)
{
	int	i;

	i = x;
	i += (p->x * (p->m->rt.r.w / IMG_THREAD));
	i *= (p->m->img[p->i].bpp / 8);
	i += ((p->m->rt.r.h - 1) - y) * (p->m->img[p->i].sl);
	pthread_mutex_lock(p->l);
	(p->m->img[p->i].addr)[i] = (int)(c.b);
	(p->m->img[p->i].addr)[++i] = (int)(c.g);
	(p->m->img[p->i].addr)[++i] = (int)(c.r);
	pthread_mutex_unlock(p->l);
}

static void	*mlx_col_calc(void *p)
{
	int		s;
	int		x;
	int		y;
	t_color	c;

	y = ((t_p *)p)->m->rt.r.h;
	while (--y >= 0)
	{
		x = -1;
		while (++x < ((t_p *)p)->m->rt.r.w / IMG_THREAD)
		{
			c = c_init(0.0, 0.0, 0.0);
			s = -1;
			while (++s < N_SAM)
				c = c_add(c, r_trace(((t_p *)p),
							r_corr(((t_p *)p), x, y), N_DEP));
			c = c_corr(c, N_SAM);
			mlx_write(c, ((t_p *)p), x, y);
		}
	}
	return (NULL);
}

void		*mlx_img_calc(void *p)
{
	int			i;
	pthread_t	*t;
	t_p			*x;
	t_mux		l;

	i = -1;
	if (pthread_mutex_init(&l, NULL))
		e_thread_exec((t_p *)p, NULL, NULL, NULL);
	if (!dalloc((void **)(&x), IMG_THREAD, sizeof(t_p)))
		e_thread_exec((t_p *)p, NULL, NULL, &l);
	if (!dalloc((void **)(&t), IMG_THREAD, sizeof(pthread_t)))
		e_thread_exec((t_p *)p, NULL, (void **)(&x), &l);
	while (++i < IMG_THREAD)
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

void		mlx_calc(t_mlx *m)
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
		cam_init(&(m->rt.c[i]), v_init(0, 1, 0), m->rt.r.ar);
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
