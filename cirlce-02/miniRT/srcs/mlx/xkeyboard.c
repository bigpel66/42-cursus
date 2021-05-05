/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xkeyboard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 00:16:11 by jseo              #+#    #+#             */
/*   Updated: 2021/05/05 13:05:48 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	print_material_status(int material)
{
	char	*s;

	s = NULL;
	ostream_title("Material", 0);
	if (material == LAMBERTIAN)
		s = "LAMBERTIAL\t";
	else if (material == METAL)
		s = "METAL\t\t";
	else if (material == DIELECTRIC)
		s = "DIELECTRIC\t";
	printf("The Material of Every Object is %s", s);
	printf("\n");
	printf("\n");
}

static void	print_filter_status(int filter)
{
	char	*s;

	s = NULL;
	ostream_title("Material", 0);
	if (filter == FILTER_NOTHING)
		s = "\t\tNOTHING";
	else if (filter == FILTER_SEPIA)
		s = "\t\tSEPIA";
	else if (filter == FILTER_RED)
		s = "\t\tRED";
	else if (filter == FILTER_GREEN)
		s = "\t\tGREEN";
	else if (filter == FILTER_BLUE)
		s = "\t\tBLUE";
	printf("The Filter of Image is %s", s);
	printf("\n");
	printf("\n");
}

t_bool		cam_key(int key, t_mlx *m)
{
	if ((key >= 0 && key <= 2) || (key >= 12 && key <= 14))
		cam_mov(key, m);
	else if ((key >= 123 && key <= 126) || (key >= 43 && key <= 44))
		cam_rot(key, m);
	else if (key >= 45 && key <= 46)
		cam_snap(key, m);
	else
		return (FALSE);
	return (TRUE);
}

t_bool		obj_key(int key, t_mlx *m)
{
	if ((key >= 18 && key <= 21) || (key >= 34 && key <= 35))
		printf("%d %d\n", key, m->rt.cnt.obj);
	// obj_mov(key, m);
	else if ((key >= 6 && key <= 9) || (key >= 40 && key <= 41))
		printf("%d %d\n", key, m->rt.cnt.obj);
	// obj_rot(key, m);
	else
		return (FALSE);
	return (TRUE);
}

t_bool		mode_key(int key, t_mlx *m)
{
	int	i;

	i = -1;
	if (key == KEY_SPACE)
	{
		while (++i < m->rt.cnt.obj)
			(m->obj)[i].mat = ((m->obj)[i].mat + 1) % 3;
		print_material_status((m->obj)[0].mat);
	}
	else if (key == KEY_ENTER)
	{
		while (++i < m->rt.cnt.obj)
			(m->obj)[i].filter = ((m->obj)[i].filter + 1) % 5;
		print_filter_status((m->obj)[0].filter);
	}
	else
		return (FALSE);
	return (TRUE);
}
