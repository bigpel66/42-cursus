/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 00:19:30 by jseo              #+#    #+#             */
/*   Updated: 2021/05/07 17:10:17 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	txr_fill(t_mlx *m, int i, unsigned char *bmp)
{
	if (*(uint16_t *)bmp != *(uint16_t *)"BM")
		return (FALSE);
	(m->txr)[i].width = *(uint32_t *)(bmp + 18);
	(m->txr)[i].height = *(uint32_t *)(bmp + 22);
	(m->txr)[i].bpp = *(uint16_t *)(bmp + 28);
	(m->txr)[i].bmp_header = *(uint32_t *)(bmp + 10) - *(uint32_t *)(bmp + 14);
	(m->txr)[i].dib_header = *(uint32_t *)(bmp + 14);
	(m->txr)[i].data = *(uint32_t *)(bmp + 2) - *(uint32_t *)(bmp + 10);
	(m->txr)[i].color = bmp;
	printf("%d\n", *bmp + 20);
	printf("width %d\n", (m->txr)[i].width);
	printf("width %d\n", *(unsigned char *)(bmp + 4));
	printf("height %d\n", (m->txr)[i].height);
	printf("bpp %d\n", (m->txr)[i].bpp);
	printf("bmp header %zu\n", (m->txr)[i].bmp_header);
	printf("dib header %zu\n", (m->txr)[i].dib_header);
	printf("data %zu\n", (m->txr)[i].data);
	return (TRUE);
}

static void		txr_process(t_mlx *m, int i, int fd)
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
	if (!txr_fill(m, i, data))
		e_texture_format((void **)(&data), m, fd);
}

static void		txr_test(t_mlx *m)
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
			txr_process(m, i, fd);
			close(fd);
		}
	}
}

t_bool			txr_init(t_mlx *m)
{
	int	i;

	i = -1;
	if (!m->rt.cnt.sp)
		return (TRUE);
	if (!dalloc((void **)(&(m->txr)), m->rt.cnt.sp, sizeof(t_txr)))
		return (FALSE);
	while (++i < m->rt.cnt.sp)
	{
		(m->txr)[i].i = i;
		(m->txr)[i].f = (m->rt.sp)[i].f;
	}
	txr_test(m);
	return (TRUE);
}

t_bool			txr_save(t_sphere *sp, char **line)
{
	size_t	len;

	if (!line || !(*line) || is_endl(*line))
		return (TRUE);
	while (**line && is_blank(**line))
		++(*line);
	len = ft_strlen(*line);
	if (!dalloc((void **)(&(sp->f)), len + 1, sizeof(char)))
		return (FALSE);
	ft_strlcpy(sp->f, *line, len + 1);
	*line = *line + len;
	return (TRUE);
}
