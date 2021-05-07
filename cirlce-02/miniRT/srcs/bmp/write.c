/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 14:56:41 by jseo              #+#    #+#             */
/*   Updated: 2021/05/07 17:23:38 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	fill_header(unsigned char *bmp, size_t data, int width, int height)
{
	*(uint16_t *)bmp = *(uint16_t *)"BM";
	*(uint32_t *)(bmp + 2) = (uint32_t)(data + BMP_HEADER + DIB_HEADER);
	*(uint32_t *)(bmp + 10) = (uint32_t)(BMP_HEADER + DIB_HEADER);
	*(uint32_t *)(bmp + 14) = (uint32_t)DIB_HEADER;
	*(uint32_t *)(bmp + 18) = (uint32_t)width;
	*(uint32_t *)(bmp + 22) = (uint32_t)height;
	*(uint16_t *)(bmp + 26) = (uint16_t)1;
	*(uint16_t *)(bmp + 28) = (uint16_t)24;
	*(uint32_t *)(bmp + 34) = (uint32_t)data;
	*(uint32_t *)(bmp + 38) = (uint32_t)3937;
	*(uint32_t *)(bmp + 42) = (uint32_t)3937;
}

static void	fill_data(unsigned char *bmp, t_mlx *m, int idx, size_t padd)
{
	int		x;
	int		y;
	size_t	bmp_idx;
	size_t	addr_idx;

	bmp_idx = BMP_HEADER + DIB_HEADER;
	y = m->rt.r.h;
	while (y--)
	{
		x = -1;
		while (++x < m->rt.r.w)
		{
			addr_idx = (y * (m->img)[idx].sl) + (x * (m->img)[idx].bpp / 8);
			*(bmp + bmp_idx++) = *((m->img)[idx].addr + addr_idx++);
			*(bmp + bmp_idx++) = *((m->img)[idx].addr + addr_idx++);
			*(bmp + bmp_idx++) = *((m->img)[idx].addr + addr_idx);
		}
		bmp_idx += padd;
	}
}

t_bool		export_bmp(t_mlx *m, int fd, int idx)
{
	size_t			data;
	size_t			header;
	unsigned char	*bmp;

	data = m->rt.r.w * m->rt.r.h * 3;
	header = BMP_HEADER + DIB_HEADER;
	if (!dalloc((void **)(&bmp), data + header, sizeof(unsigned char)))
	{
		close(fd);
		return (FALSE);
	}
	fill_header(bmp, data, m->rt.r.w, m->rt.r.h);
	fill_data(bmp, m, idx, 0);
	write(fd, bmp, data + header);
	free_ptr((void **)(&bmp));
	close(fd);
	return (TRUE);
}
