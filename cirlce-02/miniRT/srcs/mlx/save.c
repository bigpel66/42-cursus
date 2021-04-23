/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:09:03 by jseo              #+#    #+#             */
/*   Updated: 2021/04/24 00:19:24 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	inject_extname(char *s, char *f, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		s[i] = f[i];
	s[len] = '.';
	s[len + 1] = 'b';
	s[len + 2] = 'm';
	s[len + 3] = 'p';
}

void	mlx_save(t_mlx *m, char *f, int len)
{
	int		fd;
	char	*s;

	if (!dalloc((void **)(&s), len + 5, sizeof(char)))
		e_memory_alloc(m);
	inject_extname(s, f, len);
	fd = open(s, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd < 0)
		e_file_open(m);
	free_ptr((void **)(&s));
	close(fd);
}
