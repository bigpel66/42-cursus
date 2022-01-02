/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:05:13 by jseo              #+#    #+#             */
/*   Updated: 2022/01/02 10:37:40 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool compare(int c)
{
	return (c == ':');
}

static inline bool check(char *command, char *chunk, DIR *dir)
{
	bool			exist;
	char			*path;
	struct stat		data;
	struct dirent	*reader;

	exist = false;
	reader = readdir(dir);
	while (reader != NULL)
	{
		if (!jstrncmp(reader->d_name, command, BUFFER_SIZE))
		{
			path = jstrjoin(jstrjoin(chunk, "/"), reader->d_name);
			if (lstat(path, &data) != ERROR)
				if (data.st_mode & S_IXUSR)
					exist = true;
		}
		reader = readdir(dir);
	}
	if (exist)
		closedir(dir);
	return (exist);
}

static inline char	*search(char *command, char *candidate)
{
	char	**chunks;
	DIR		*current;

	chunks = jsplit(candidate, compare);
	while (*chunks != NULL)
	{
		current = opendir(*chunks);
		if (current == NULL)
		{
			++chunks;
			continue ;
		}
		if (check(command, *chunks, current))
			break ;
		closedir(current);
		++chunks;
	}
	return (*chunks);
}

char	*find(char *command, t_rb *envmap)
{
	char	*path;
	char	*candidate;

	candidate = jstrdup(get_value(envmap, "PATH"));
	if (candidate == NULL)
	{
		errno = ENOENT;
		finish(command, true);
	}
	path = search(command, candidate);
	if (path != NULL)
		return (jstrjoin(jstrjoin(path, "/"), command));
	else
	{
		errno = EFAULT;
		finish(command, true);
	}
	return (NULL);
}

char	*resolve(char *command, t_rb *envmap)
{
	int		ret;
	char	*sep;
	char	*pwd;
	char	*path;

	sep = command;
	while (jstrchr(sep + 1, '/') != NULL)
		sep = jstrchr(sep + 1, '/');
	*sep = '\0';
	ret = chdir(command);
	*sep = '/';
	if (ret < 0)
	{
		errno = ENOENT;
		finish(command, true);
	}
	pwd = getcwd(NULL, 0);
	path = search(sep + 1, pwd);
	if (path == NULL)
	{
		errno = ENOENT;
		finish(command, true);
	}
	chdir(get_value(envmap, "PWD"));
	return (jstrjoin(pwd, sep));
}
