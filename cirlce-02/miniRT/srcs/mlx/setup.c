/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:44:34 by jseo              #+#    #+#             */
/*   Updated: 2021/04/25 01:07:52 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	print_image_status(t_mlx *m)
{
	int		i;
	char	*s;

	i = -1;
	while (++i < m->rt.cnt.c)
	{
		ostream_title("Image", i + 1);
		printf("Image Identifier\t\t%p\n", (m->img)[i].id);
		printf("Image Data Address\t\t%p\n", (m->img)[i].addr);
		printf("Image Bits Per Pixel\t\t%d\n", (m->img)[i].bpp);
		printf("Image Size Line\t\t\t%d\n", (m->img)[i].sl);
		if ((m->img)[i].endian)
			s = "Big Endian";
		else
			s = "Little Endian";
		printf("Image Endian\t\t\t%s\n", s);
		printf("\n");
	}
}

static void	img_init(t_mlx *m)
{
	int		idx;
	t_img	*i;

	idx = -1;
	while (++idx < m->rt.cnt.c)
	{
		i = &((m->img)[idx]);
		i->id = mlx_new_image(m->sid, m->rt.r.w, m->rt.r.h);
		if (!(i->id))
			e_mlx_image(m);
		i->addr = mlx_get_data_addr(i->id, &(i->bpp), &(i->sl), &(i->endian));
	}
	print_image_status(m);
}

void		mlx_setup(t_mlx *m, char *f)
{
	t_scene	*rt;

	rt = &(m->rt);
	if (rt->r.w <= 0 || rt->r.h <= 0 || !rt->cnt.c)
		e_mlx_setup(m);
	m->sid = mlx_init();
	if (!(m->sid))
		e_mlx_screen_connection(m);
	m->wid = mlx_new_window(m->sid, rt->r.w, rt->r.h, f);
	if (!(m->wid))
		e_mlx_window(m);
	if (!dalloc((void **)(&(m->img)), m->rt.cnt.c, sizeof(t_img)))
		e_memory_alloc(m);
	img_init(m);
}
