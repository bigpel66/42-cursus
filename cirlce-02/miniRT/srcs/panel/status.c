/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:54:31 by jseo              #+#    #+#             */
/*   Updated: 2021/05/07 17:39:16 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_scene_status(t_scene *rt)
{
	ostream_title("Count", 0);
	if (rt->cnt.r == 1)
		printf("Resolution\t\t\tReady\n");
	else
		printf("Resolution\t\t\tNot Exist\n");
	if (rt->cnt.a == 1)
		printf("Ambient\t\t\t\tReady\n");
	else
		printf("Ambient\t\t\t\tNot Exist\n");
	printf("%s%d\n", "The Number of Camera\t\t", rt->cnt.c);
	printf("%s%d\n", "The Number of Light\t\t", rt->cnt.l);
	printf("%s%d\n", "The Number of Sphere\t\t", rt->cnt.sp);
	printf("%s%d\n", "The Number of Plane\t\t", rt->cnt.pl);
	printf("%s%d\n", "The Number of Square\t\t", rt->cnt.sq);
	printf("%s%d\n", "The Number of Cylinder\t\t", rt->cnt.cy);
	printf("%s%d\n", "The Number of Triangle\t\t", rt->cnt.tr);
	printf("%s%d\n", "The Number of Cone\t\t", rt->cnt.co);
	printf("%s%d\n", "Object Count\t\t\t", rt->cnt.obj);
	printf("\n");
}

void	print_object_status(t_mlx *m)
{
	int		i;
	char	*s;

	i = -1;
	ostream_title("Object", 0);
	while (++i < m->rt.cnt.obj)
	{
		if ((m->obj)[i].type == SPHERE)
			s = "SPHERE\t";
		else if ((m->obj)[i].type == PLANE)
			s = "PLANE\t";
		else if ((m->obj)[i].type == SQUARE)
			s = "SQUARE\t";
		else if ((m->obj)[i].type == CYLINDER)
			s = "CYLINDER";
		else if ((m->obj)[i].type == TRIANGLE)
			s = "TRIANGLE";
		else
			s = "CONE";
		printf("The Type of Index\t%6d\'s Object\t\t%s", i, s);
		if ((m->obj)[i].data)
			printf("\tData\n\n");
		else
			printf("\tNo Data\n\n");
	}
}

void	print_image_status(t_mlx *m)
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

void	print_material_status(int material)
{
	char	*s;

	s = NULL;
	ostream_title("Material", 0);
	if (material == LAMBERTIAN)
		s = "LAMBERTIAN\t";
	else if (material == METAL)
		s = "METAL\t\t";
	else if (material == DIELECTRIC)
		s = "DIELECTRIC\t";
	printf("The Material of Every Object is %s", s);
	printf("\n");
	printf("\n");
}

void	print_filter_status(int filter)
{
	char	*s;

	s = NULL;
	ostream_title("Filter", 0);
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
