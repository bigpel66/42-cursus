/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 00:19:30 by jseo              #+#    #+#             */
/*   Updated: 2021/05/07 17:55:49 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	fill_txr(t_mlx *m, int i, unsigned char *bmp)
{
	if (*(uint16_t *)bmp != *(uint16_t *)"BM")
		return (FALSE);
	(m->txr)[i].width = *(uint32_t *)(bmp + 18);
	(m->txr)[i].height = *(uint32_t *)(bmp + 22);
	(m->txr)[i].bpp = *(uint16_t *)(bmp + 28);
	(m->txr)[i].b_h = *(uint32_t *)(bmp + 10) - *(uint32_t *)(bmp + 14);
	(m->txr)[i].d_h = *(uint32_t *)(bmp + 14);
	(m->txr)[i].data = *(uint32_t *)(bmp + 2) - *(uint32_t *)(bmp + 10);
	(m->txr)[i].sl = ((m->txr)[i].bpp / 8) * (m->txr)[i].width;
	(m->txr)[i].color = bmp;
	ostream_title("Texture of Sphere", i + 1);
	ostream_floating_point((m->txr)[i].width, "Width\t\t\t");
	ostream_floating_point((m->txr)[i].height, "Height\t\t\t");
	ostream_floating_point((m->txr)[i].bpp, "Bits Per Pixel\t\t");
	ostream_floating_point((m->txr)[i].sl, "Size Line\t\t");
	ostream_floating_point((m->txr)[i].b_h, "BMP Header Size\t\t");
	ostream_floating_point((m->txr)[i].d_h, "DIB Header Size\t\t");
	ostream_floating_point((m->txr)[i].data, "Data Size\t\t");
	ostream_endl();
	return (TRUE);
}

static void		read_bmp(t_mlx *m, int i, int fd)
{
	int				cnt;
	unsigned char	*buf;
	unsigned char	*data;
	int				ret;

	cnt = 0;
	buf = NULL;
	data = NULL;
	if (!dalloc((void **)(&buf), BUFFER_SIZE, sizeof(unsigned char)))
		e_texture_alloc(NULL, m, fd);
	while (TRUE)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
			e_texture_read((void **)(&buf), (void **)(&data), m, fd);
		if (!ft_memappend((void **)(&data), data, buf, ++cnt))
			e_texture_alloc((void **)(&buf), m, fd);
		if (!ret)
			break ;
	}
	free_ptr((void **)(&buf));
	if (!fill_txr(m, i, data))
		e_texture_format((void **)(&data), m, fd);
}

void			import_bmp(t_mlx *m)
{
	int	i;
	int	fd;

	i = -1;
	while (++i < m->rt.cnt.sp)
	{
		if ((m->txr)[i].f)
		{
			fd = open((m->txr)[i].f, O_RDONLY);
			if (fd < 0)
			{
				write(STDERR_FILENO, "Detail: Invalid sphere texture\n", 31);
				e_file_open(m);
			}
			read_bmp(m, i, fd);
			close(fd);
		}
	}
}
