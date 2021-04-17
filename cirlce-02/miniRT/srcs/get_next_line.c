/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 11:16:16 by jseo              #+#    #+#             */
/*   Updated: 2021/04/17 16:44:05 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static ssize_t	check_newline(char *mem)
{
	ssize_t	i;

	i = -1;
	while (mem[++i])
		if (mem[i] == '\n')
			return (i);
	return (-1);
}

static int		split_line(char **mem, char **line, ssize_t idx)
{
	char	*tmp;

	(*mem)[idx] = '\0';
	*line = ft_strdup(*mem);
	if (!ft_strlen(*mem + idx + 1))
	{
		free_ptr((void **)(mem));
		return (1);
	}
	tmp = ft_strdup(*mem + idx + 1);
	free_ptr((void **)(mem));
	*mem = tmp;
	return (1);
}

static int		exception_line(char **mem, char **line, ssize_t size)
{
	ssize_t	idx;

	if (size < 0)
		return (-1);
	if (*mem)
	{
		idx = check_newline(*mem);
		if (idx >= 0)
			return (split_line(mem, line, idx));
	}
	else if (*mem)
	{
		*line = *mem;
		*mem = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int				get_next_line(int fd, char **line)
{
	ssize_t		size;
	ssize_t		idx;
	char		*buf;
	static char	*mem[OPEN_MAX + 3];

	if (fd < 0 || !line || BUFFER_SIZE < 1 || OPEN_MAX <= fd)
		return (-1);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	size = read(fd, buf, BUFFER_SIZE);
	while (size > 0)
	{
		buf[size] = '\0';
		mem[fd] = ft_strappend(mem[fd], buf);
		idx = check_newline(mem[fd]);
		if (idx >= 0)
		{
			free_ptr((void **)(&buf));
			return (split_line(&mem[fd], line, idx));
		}
		size = read(fd, buf, BUFFER_SIZE);
	}
	free_ptr((void **)(&buf));
	return (exception_line(&mem[fd], line, size));
}
