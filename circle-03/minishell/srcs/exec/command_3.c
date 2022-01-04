/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:05:13 by jseo              #+#    #+#             */
/*   Updated: 2022/01/04 15:21:34 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** compare ()			- Compare Function Whether a Character Equal to :
**
** return				- True or False
** c					- A Character to be Compared
*/

bool	compare(int c)
{
	return (c == ':');
}

/*
** check ()				- Current Directory Entry Holds the Execution File
**
** return				- True or False
** command				- Command to Execute
** chunk				- A Chunk from Splitted Candidates
** current				- Current Directory Entry
** exist				- Current Directory Entry Holds the Execution File
** abs					- Absolute Path
** data					- Stat Info of Absolute Path
** reader				- A Element of Current Directory Entry
*/

static inline bool	check(char *command, char *chunk, DIR *current)
{
	bool			exist;
	char			*abs;
	struct stat		data;
	struct dirent	*reader;

	exist = false;
	reader = readdir(current);
	while (reader != NULL)
	{
		if (!jstrncmp(reader->d_name, command, BUFFER_SIZE))
		{
			abs = jstrjoin(jstrjoin(chunk, "/"), reader->d_name);
			if (lstat(abs, &data) != ERROR)
				if (data.st_mode & S_IXUSR)
					exist = true;
		}
		reader = readdir(current);
	}
	if (exist)
		closedir(current);
	return (exist);
}

/*
** search ()			- Search the Absolute Path Which Holds the Command
**
** return				- Absolute Path
** command				- Command to Execute
** candidates			- Candidate Paths to Return Absolute Path
** chunks				- Chunks from Splitted Candidates
** current				- Current Directory Entry
*/

static inline char	*search(char *command, char *candidates)
{
	char	**chunks;
	DIR		*current;

	chunks = jsplit(candidates, compare);
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

/*
** find ()				- Find the Absolute Path to Execute the Command
**
** return				- Absolute Path
** command				- Command to Execute
** envmap				- Variable for Maps the Environment Variables
** abs					- Absolute Path
** candidates			- Candidate Paths to Return Absolute Path
*/

char	*find(char *command, t_rb *envmap)
{
	char	*abs;
	char	*candidates;

	candidates = jstrdup(get_value(envmap, "PATH"));
	if (candidates == NULL)
	{
		errno = ENOENT;
		finish(command, true);
	}
	abs = search(command, candidates);
	if (abs != NULL)
		return (jstrjoin(jstrjoin(abs, "/"), command));
	else
	{
		errno = EFAULT;
		finish(command, true);
	}
	return (NULL);
}

/*
** resolve ()			- Resolve the Relative Path to Execute the Command
**
** return				- Absolute Path
** command				- Command to Execute
** envmap				- Variable for Maps the Environment Variables
** ret					- Return Value of Change Directory
** sep					- Boundary of Relative Path
** abs					- Absolute Path
*/

char	*resolve(char *command, t_rb *envmap)
{
	int		ret;
	char	*sep;
	char	*abs;

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
	abs = getcwd(NULL, 0);
	if (search(sep + 1, abs) == NULL)
	{
		errno = ENOENT;
		finish(command, true);
	}
	chdir(get_value(envmap, "PWD"));
	return (jstrjoin(abs, sep));
}
