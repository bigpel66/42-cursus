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
		return (SUCCESS);
	}
	tmp = ft_strdup(*mem + idx + 1);
	free_ptr((void **)(mem));
	*mem = tmp;
	return (SUCCESS);
}

static int		exception_line(char **mem, char **line, ssize_t size)
{
	ssize_t	idx;

	idx = -1;
	if (size < 0)
		return (ERROR);
	if (*mem)
	{
		idx = check_newline(*mem);
		if (idx >= 0)
			return (split_line(mem, line, idx));
		else
		{
			*line = *mem;
			*mem = NULL;
			return (END);
		}
	}
	*line = ft_strdup("");
	return (END);
}

int				ft_gnl(int fd, char **line)
{
	ssize_t		ret;
	char		*buf;
	static char	*mem[OPEN_MAX + 3];

	if (fd < 0 || !line || BUFFER_SIZE < 1 || OPEN_MAX <= fd)
		return (ERROR);
	if (!dalloc((void **)(&buf), BUFFER_SIZE + 1, sizeof(char)))
		return (ERROR);
	ret = read(fd, buf, BUFFER_SIZE);
	while (ret > 0)
	{
		buf[ret] = '\0';
		mem[fd] = ft_strappend(mem[fd], buf);
		if (!mem[fd])
			return (ERROR);
		ret = check_newline(mem[fd]);
		if (ret >= 0)
		{
			free_ptr((void **)(&buf));
			return (split_line(&mem[fd], line, ret));
		}
		ret = read(fd, buf, BUFFER_SIZE);
	}
	free_ptr((void **)(&buf));
	return (exception_line(&mem[fd], line, ret));
}
