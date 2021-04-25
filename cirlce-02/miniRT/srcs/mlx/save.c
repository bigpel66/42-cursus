/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:09:03 by jseo              #+#    #+#             */
/*   Updated: 2021/04/25 13:48:46 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		prefix_file(t_mlx *m, int *prefix)
{
	int	cnt;

	*prefix = 0;
	cnt = m->rt.cnt.c;
	while (1)
	{
		++(*prefix);
		cnt /= 10;
		if (!cnt)
			break ;
	}
	++(*prefix);
}

static void		infix_file(char *s, char *f, int prefix, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		s[i + prefix] = f[i];
}

static void		suffix_file(char *s, int suffix)
{
	s[suffix] = '.';
	s[suffix + 1] = 'b';
	s[suffix + 2] = 'm';
	s[suffix + 3] = 'p';
}

static t_bool	create_multiple_file(t_mlx *m, char *s, int prefix)
{
	int	i;
	int	j;
	int	tmp;
	int	fd;

	s[prefix - 1] = '_';
	i = -1;
	while (++i < m->rt.cnt.c)
	{
		j = -1;
		tmp = i;
		while (++j < prefix - 1)
		{
			s[prefix - j - 2] = DECIMAL[tmp % 10];
			tmp /= 10;
		}
		fd = open(s, O_CREAT | O_TRUNC | O_RDWR, 0644);
		if (fd < 0)
			return (FALSE);
		if (!export_bmp(m, fd, i))
			return (FALSE);
		close(fd);
	}
	return (TRUE);
}

void			mlx_save(t_mlx *m, char *f, int len)
{
	char	*s;
	int		prefix;

	prefix_file(m, &prefix);
	if (!dalloc((void **)(&s), len + prefix + 5, sizeof(char)))
		e_memory_alloc(m);
	infix_file(s, f, prefix, len);
	suffix_file(s, prefix + len);
	if (!create_multiple_file(m, s, prefix))
	{
		free_ptr((void **)(&s));
		e_file_open(m);
	}
	free_ptr((void **)(&s));
}
