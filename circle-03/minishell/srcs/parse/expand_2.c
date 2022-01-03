/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:00:58 by jseo              #+#    #+#             */
/*   Updated: 2022/01/03 20:03:23 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** expand_space ()		- Split the Expanded String with $ by Spaces
**
** return				- void
** value				- Value from the Specific Key on the Envmap
** brace				- Chunks of the Separated String after Expansion
** append				- Splited Chunk to be Appended
** search				- Position of a Space
*/

static inline void	expand_space(char *value, t_lst **brace)
{
	t_lst	*append;
	char	*search;

	*brace = NULL;
	search = value;
	while (true)
	{
		search = jstrchr(value, ' ');
		if (search == NULL)
			break ;
		*search++ = '\0';
		append = jlstnew(jstrdup(value));
		mini_assert(append != NULL && append->content != NULL, \
			MASSERT "(append != NULL && append->content != NULL), " \
			EXPAND_SPACE MEXPAND_1_FILE "line 39.");
		value = search;
		jlstadd_back(brace, append);
	}
	if (!*value)
		return ;
	append = jlstnew(jstrdup(value));
	mini_assert(append != NULL && append->content != NULL, \
		MASSERT "(append != NULL && append->content != NULL), " \
		EXPAND_SPACE MEXPAND_1_FILE "line 48.");
	jlstadd_back(brace, append);
}

/*
** expand_brace ()		- Gather the Splitted Chunks into a String
**
** return				- Expanded String
** brace				- To Gather the Separated String after Expansion
** ret					- Returned Value after String Append
** middle				- String to be Appended
** origin				- Origin Point of Chunks to be Freed
*/

static inline char	*expand_brace(t_lst *brace)
{
	bool	ret;
	char	*middle;
	t_lst	*origin;

	middle = NULL;
	origin = brace;
	ret = jstrappend(&middle, (char *)(brace->content));
	mini_assert(ret, MASSERT "(ret), " EXPAND_BRACE MEXPAND_1_FILE "line 73.");
	while (brace->next != NULL)
	{
		brace = brace->next;
		ret = jstrappend(&middle, "\\ ");
		mini_assert(ret, \
			MASSERT "(ret), " EXPAND_BRACE MEXPAND_1_FILE "line 78.");
		ret = jstrappend(&middle, (char *)(brace->content));
		mini_assert(ret, \
			MASSERT "(ret), " EXPAND_BRACE MEXPAND_1_FILE "line 81.");
	}
	jlstclear(&origin, jfree);
	return (middle);
}

/*
** expand_middle ()		- Expand String with $
**
** return				- Expanded String
** input				- Variable for a User Input
** it					- Variable for Iterating the Input
** last					- A String after $
** envmap				- Variable for Maps the Environment Variables
** key					- Specific Key to Find the Value
** value				- Value from the Specific Key on the Envmap
** brace				- Chunks of the Separated String after Expansion
*/

static inline char	*expand_middle(char *input, char *it, char *last, \
									t_rb *envmap)
{
	char	*key;
	char	*value;
	t_lst	*brace;

	if (last - it == 1)
		return (jstrdup("$"));
	key = jsubstr(input, it - input + 1, last - it - 1);
	value = get_value(envmap, key);
	if (value == NULL)
		value = "";
	jfree((void **)(&key));
	value = jstrdup(value);
	if (value == NULL || !*value)
		return (value);
	expand_space(value, &brace);
	mini_assert(brace != NULL, \
		MASSERT "(brace != NULL), " EXPAND_MIDDLE MEXPAND_1_FILE "line 118.");
	jfree((void **)(&value));
	return (expand_brace(brace));
}

/*
** expand_last ()		- Find the Beginning Address after $
**
** return				- Address after $
** it					- Variable for Iterating the Input
*/

static inline char	*expand_last(char *it)
{
	if (*it && jstrchr("$?$#*", *it))
		++it;
	else
		while (*it && !jstrchr(" ><\'\"|?$", *it))
			++it;
	return (it);
}

/*
** expand_internal ()	- Expand Logic
**
** return				- Expanded String
** input				- Variable for a User Input
** it					- Variable for Iterating the Input
** envmap				- Variable for Maps the Environment Variables
** d_quote				- Whether the Input Braced by Double Quotes
** first				- A String before $
** last					- A String after $
** middle				- A Expanded String from $
** former				- first + middle
** latter				- Expanded string from last by Recursion
*/

char	*expand_internal(char *input, char *it, t_rb *envmap, bool d_quote)
{
	char	*first;
	char	*last;
	char	*middle;
	char	*former;
	char	*latter;

	first = jsubstr(input, 0, it - input);
	last = expand_last(it + 1);
	middle = expand_middle(input, it, last, envmap);
	last = jstrdup(last);
	former = jstrjoin(first, middle);
	latter = expand(last, envmap, d_quote);
	jfree((void **)(&middle));
	jfree((void **)(&first));
	jfree((void **)(&input));
	input = jstrjoin(former, latter);
	jfree((void **)(&latter));
	jfree((void **)(&former));
	return (input);
}
