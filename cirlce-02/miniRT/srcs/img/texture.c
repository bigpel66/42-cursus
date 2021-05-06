/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 00:19:30 by jseo              #+#    #+#             */
/*   Updated: 2021/05/07 00:32:34 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	txr_test(t_mlx *m)
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
			close(fd);
		}
	}
}

t_bool		txr_init(t_mlx *m)
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

t_bool		txr_save(t_sphere *sp, char **line)
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
