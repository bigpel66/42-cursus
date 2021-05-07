/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 11:16:16 by jseo              #+#    #+#             */
/*   Updated: 2021/04/22 17:10:14 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	check_newline(char *mem, ssize_t *ret)
{
	ssize_t	i;

	i = -1;
	while (mem[++i])
	{
		if (mem[i] == '\n')
		{
			*ret = i;
			return (TRUE);
		}
	}
	*ret = -1;
	return (FALSE);
}

static int		split_line(char **mem, char **line, ssize_t idx)
{
	char	*tmp;

	(*mem)[idx] = '\0';
	*line = ft_strdup(*mem);
	if (!*line)
	{
		free_ptr((void **)(mem));
		return (ERROR);
	}
	if (!ft_strlen(*mem + idx + 1))
	{
		free_ptr((void **)(mem));
		return (SUCCESS);
	}
	tmp = *mem;
	*mem = ft_strdup(tmp + idx + 1);
	free_ptr((void **)(&tmp));
	if (!*mem)
		return (ERROR);
	return (SUCCESS);
}

static int		exception_line(char **mem, char **line, ssize_t size)
{
	ssize_t	idx;

	idx = -1;
	if (size < 0)
	{
		free_ptr((void **)(mem));
		return (ERROR);
	}
	if (*mem)
	{
		if (check_newline(*mem, &idx))
			return (split_line(mem, line, idx));
		*line = *mem;
		*mem = NULL;
		return (END);
	}
	if (!dalloc((void **)(line), 1, sizeof(char)))
	{
		free_ptr((void **)(mem));
		return (ERROR);
	}
	return (END);
}

int				ft_gnl(int fd, char **line)
{
	ssize_t		ret;
	char		*buf;
	static char	*mem[OPEN_MAX + 3];

	if (fd < 0 || !line || BUFFER_SIZE < 1 || OPEN_MAX <= fd ||
			!dalloc((void **)(&buf), BUFFER_SIZE + 1, sizeof(char)))
		return (ERROR);
	while (TRUE)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret <= 0)
			break ;
		if (!ft_strappend(&(mem[fd]), mem[fd], buf))
		{
			free_ptr((void **)(&buf));
			return (ERROR);
		}
		if (check_newline(mem[fd], &ret))
		{
			free_ptr((void **)(&buf));
			return (split_line(&mem[fd], line, ret));
		}
	}
	free_ptr((void **)(&buf));
	return (exception_line(&mem[fd], line, ret));
}
