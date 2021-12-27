/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:00:58 by jseo              #+#    #+#             */
/*   Updated: 2021/12/27 12:25:09 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static inline void	expand_space(char *value, t_lst **brace)
{
	t_lst	*append;
	char	*search;

	*brace = NULL;
	search = value;
	while (true)
	{
		search = jstrchr(value, ' ');
		if (!search)
			break ;
		*search++ = '\0';
		append = jlstnew(jstrdup(value));
		mini_assert(append != NULL && append->content != NULL, \
			MASSERT "(append != NULL && append->content != NULL), " \
			EXPAND_SPACE MEXPAND_1_FILE "line 29.");
		value = search;
		jlstadd_back(brace, append);
	}
	if (!*value)
		return ;
	append = jlstnew(jstrdup(value));
	mini_assert(append != NULL && append->content != NULL, \
		MASSERT "(append != NULL && append->content != NULL), " \
		EXPAND_SPACE MEXPAND_1_FILE "line 38.");
	jlstadd_back(brace, append);
}

static inline char	*expand_brace(t_lst *brace)
{
	bool	ret;
	char	*middle;
	t_lst	*origin;

	middle = NULL;
	origin = brace;
	ret = jstrappend(&middle, (char *)(brace->content));
	mini_assert(ret, MASSERT "(ret), " EXPAND_BRACE MEXPAND_1_FILE "line 53.");
	while (brace->next)
	{
		brace = brace->next;
		ret =jstrappend(&middle, "\\ ");
		mini_assert(ret, \
			MASSERT "(ret), " EXPAND_BRACE MEXPAND_1_FILE "line 58.");
		ret = jstrappend(&middle, (char *)(brace->content));
		mini_assert(ret, \
			MASSERT "(ret), " EXPAND_BRACE MEXPAND_1_FILE "line 61.");
	}
	jlstclear(&origin, jfree);
	return (middle);
}

static inline char	*expand_middle(char *input, char *iter, char *last, t_rb *envmap)
{
	char	*key;
	char	*value;
	t_lst	*brace;

	if (last - iter == 1)
		return (jstrdup("$"));
	key = jsubstr(input, iter - input + 1, last - iter - 1);
	value = get_value(envmap, key);
	if (!value)
		value = "";
	jfree((void **)(&key));
	value = jstrdup(value);
	if (!value || !*value)
		return (value);
	expand_space(value, &brace);
	mini_assert(brace != NULL, \
		MASSERT "(brace != NULL), " EXPAND_MIDDLE MEXPAND_1_FILE "line 85.");
	jfree((void **)(&value));
	return (expand_brace(brace));
}

static inline char	*expand_last(char *iter)
{

	if (*iter && jstrchr("$?$#*", *iter))
		++iter;
	else
		while (*iter && !jstrchr(" ><\'\"|?$", *iter))
			++iter;
	return (iter);
}

char	*expand_internal(char *input, char *iter, t_rb *envmap, bool d_quote)
{
	char	*first;
	char	*last;
	char	*middle;
	char	*former;
	char	*latter;

	first = jsubstr(input, 0, iter - input);
	last = expand_last(iter + 1);
	middle = expand_middle(input, iter, last, envmap);
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

