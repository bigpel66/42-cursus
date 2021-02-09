/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 11:16:16 by jseo              #+#    #+#             */
/*   Updated: 2021/02/09 17:01:10 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	check_newline(char *mem)
{
	ssize_t	i;

	i = -1;
	while (mem[++i])
		if (mem[i] == '\n')
			return (i);
	return (-1);
}

int		split_line(char **mem, char **line, ssize_t idx)
{
	char	*tmp;

	(*mem)[idx] = '\0';
	*line = ft_strdup(*mem);
	if (!ft_strlen(*mem + idx + 1))
	{
		free(*mem);
		*mem = NULL;
		return (1);
	}
	tmp = ft_strdup(*mem + idx + 1);
	free(*mem);
	*mem = tmp;
	return (1);
}

int		exception_line(char **mem, char **line, ssize_t size)
{
	ssize_t	idx;

	if (size < 0)
		return (-1);
	if (*mem && (idx = check_newline(*mem)) >= 0)
		return (split_line(mem, line, idx));
	else if (*mem)
	{
		*line = *mem;
		*mem = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*mem[OPEN_MAX];
	ssize_t		size;
	ssize_t		idx;
	char		*buf;

	if (fd < 0 || !line || BUFFER_SIZE < 1 ||
			!(buf = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	while ((size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size] = '\0';
		mem[fd] = ft_strappend(mem[fd], buf);
		if ((idx = check_newline(mem[fd])) >= 0)
		{
			free(buf);
			buf = NULL;
			return (split_line(&mem[fd], line, idx));
		}
	}
	free(buf);
	buf = NULL;
	return (exception_line(&mem[fd], line, size));
}
