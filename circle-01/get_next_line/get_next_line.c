/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 11:16:16 by jseo              #+#    #+#             */
/*   Updated: 2021/05/12 00:47:57 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_bool	ft_strappend(char **s, char *s1, char *s2)
{
	if (!s1)
	{
		free_ptr((void **)(&s1));
		*s = ft_strdup(s2);
		if (!*s)
			return (FALSE);
		return (TRUE);
	}
	if (!dalloc((void **)(s), ft_strlen(s1) + ft_strlen(s2) + 1, 1))
	{
		free_ptr((void **)(&s1));
		return (FALSE);
	}
	ft_strlcpy(*s, s1, ft_strlen(s1) + 1);
	ft_strlcpy(*s + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	free_ptr((void **)(&s1));
	return (TRUE);
}

static t_bool	check_newline(char *mem, int *ret)
{
	int			i;

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
	*mem = ft_strdup(*mem + idx + 1);
	free_ptr((void **)(&tmp));
	if (!*mem)
		return (ERROR);
	return (SUCCESS);
}

static int		exception_line(char **mem, char **line, int ret, char **buf)
{
	int			idx;

	idx = -1;
	free_ptr((void **)(buf));
	if (ret < 0)
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

int				get_next_line(int fd, char **line)
{
	char		*buf;
	int			ret;
	static char	*mem[OPEN_MAX + 3];

	if (fd < 0 || !line || BUFFER_SIZE < 1 || OPEN_MAX <= fd ||
		!dalloc((void **)(&buf), BUFFER_SIZE + 1, sizeof(char)))
		return (ERROR);
	while (TRUE)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
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
			return (split_line(&(mem[fd]), line, ret));
		}
	}
	return (exception_line(&(mem[fd]), line, ret, &buf));
}
