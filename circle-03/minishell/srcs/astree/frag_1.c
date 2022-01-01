/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frag_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:17:17 by jseo              #+#    #+#             */
/*   Updated: 2022/01/01 12:46:54 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astree.h"

/*
** as_init ()			- Initiation to Use AS Tree
**
** return				- AS Tree
** chunks				- Chunks to Build AS Tree
** syntax				- AS Tree
** frag					- Specific Syntax Node
*/

t_as	*as_init(t_lst *chunks)
{
	t_as	*syntax;
	t_as	*frag;

	syntax = NULL;
	while (chunks != NULL)
	{
		frag = make_frag(chunks);
		as_assert(frag != NULL, \
			AASSERT "(frag != NULL), " AS_INIT AFRAG_1_FILE "line 33.");
		syntax = as_insert(syntax, frag);
		chunks = chunks->next;
	}
	return (syntax);
}

/*
** identity ()			- Allocate Identity to the Syntax Node
**
** return				- void
** frag					- A New Syntax Node
** type					- Syntax Type
** exec_rdr				- Exec Function of Redirection
** exec_pipe			- Exec Function of Pipe
** exec_cmd				- Exec Function of Command
*/

static inline void	identity(t_as *frag, t_type type)
{
	extern void	exec_rdr(t_as *syntax, t_rb *envmap);
	extern void	exec_pipe(t_as *syntax, t_rb *envmap);
	extern void	exec_cmd(t_as *syntax, t_rb *envmap);

	frag->type = type;
	if (type == RDR)
		frag->exec = exec_rdr;
	else if (type == PIPE)
		frag->exec = exec_pipe;
	else
		frag->exec = exec_cmd;
}

/*
** make_frag ()			- Create a New Syntax Node for Using in AS Tree
**
** return				- A New Syntax Node
** chunk				- Chunk to Build Syntax Node
** frag					- A New Syntax Node
** data					- Data for Syntax Node
*/

t_as	*make_frag(t_lst *chunk)
{
	t_as		*frag;
	char		*data;


	data = (char *)(chunk->content);
	if (!jcalloc((void **)(&frag), 1, sizeof(t_as)))
		return (NULL);
	if (!jstrncmp(">", data, BUFFER_SIZE)
		|| !jstrncmp(">>", data, BUFFER_SIZE)
		|| !jstrncmp("<", data, BUFFER_SIZE)
		|| !jstrncmp("<<", data, BUFFER_SIZE))
		identity(frag, RDR);
	else if (!jstrncmp("|", data, BUFFER_SIZE))
		identity(frag, PIPE);
	else
		identity(frag, CMD);
	frag->token = data;
	frag->left = NULL;
	frag->right = NULL;
	return (frag);
}
