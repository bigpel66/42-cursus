/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:54:31 by jseo              #+#    #+#             */
/*   Updated: 2021/05/05 20:54:58 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
		s = "LAMBERTIAL\t";
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
