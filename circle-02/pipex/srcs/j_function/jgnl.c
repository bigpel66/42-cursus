/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jgnl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:32:11 by jseo              #+#    #+#             */
/*   Updated: 2021/07/07 19:55:10 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static bool	check_newline(char *mem, int *ret)
{
	int	i;

	i = -1;
	while (mem[++i])
	{
		if (mem[i] == '\n')
		{
			*ret = i;
			return (true);
		}
	}
	*ret = -1;
	return (false);
}

static int	split_line(char **mem, char **line, ssize_t idx)
{
	char	*tmp;

	(*mem)[idx] = '\0';
	*line = jstrdup(*mem);
	if (!*line)
	{
		jfree((void **)(mem));
		return (ERROR);
	}
	if (!jstrlen(*mem + idx + 1))
	{
		jfree((void **)(mem));
		return (SUCCESS);
	}
	tmp = *mem;
	*mem = jstrdup(*mem + idx + 1);
	jfree((void **)(&tmp));
	if (!*mem)
		return (ERROR);
	return (SUCCESS);
}

static int	exception_line(char **mem, char **line, int ret, char **buf)
{
	int	idx;

	idx = -1;
	jfree((void **)(buf));
	if (ret < 0)
	{
		jfree((void **)(mem));
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
	if (!jcalloc((void **)(line), 1, sizeof(char)))
	{
		jfree((void **)(mem));
		return (ERROR);
	}
	return (END);
}

int	jgnl(int fd, char **line)
{
	char		*buf;
	int			ret;
	static char	*mem[OPEN_MAX + 3];

	if (fd < 0 || !line || BUFFER_SIZE < 1 || OPEN_MAX <= fd
		|| !jcalloc((void **)(&buf), BUFFER_SIZE + 1, sizeof(char)))
		return (ERROR);
	while (true)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret <= 0)
			break ;
		buf[ret] = '\0';
		if (!jstrappend(&(mem[fd]), buf))
		{
			jfree((void **)(&buf));
			return (ERROR);
		}
		if (check_newline(mem[fd], &ret))
		{
			jfree((void **)(&buf));
			return (split_line(&(mem[fd]), line, ret));
		}
	}
	return (exception_line(&(mem[fd]), line, ret, &buf));
}
