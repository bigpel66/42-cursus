/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:41:44 by jseo              #+#    #+#             */
/*   Updated: 2021/12/27 02:28:09 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand(char *input, t_rb *envmap, bool d_quote);

void	mini_assert(bool condition, char *context)
{
	if (condition)
		return ;
	jputendl(context, STDERR_FILENO);
	exit(GENERAL);
}

void	pair(t_rb *envmap, char **envp)
{
	char	*value;

	while (*envp)
	{
		value = jstrchr(*envp, '=');
		*value++ = '\0';
		rb_insert(envmap, jstrdup(*envp++), jstrdup(value));
	}
	// if no PS1, use "minishell$ "
	rb_insert(envmap, jstrdup("PS1"), jstrdup("minishell$ "));
	// print_order(envmap->root);
}

void	expand_space(char *value, t_lst **brace)
{
	t_lst	*append;
	char	*search;

	*brace = NULL;
	append = NULL;
	search = value;
	while (true)
	{
		search = jstrchr(value, ' ');
		if (!search)
			break ;
		*search++ = '\0';
		append = jlstnew(jstrdup(value));
		mini_assert(append != NULL && append->content != NULL, \
			ASSERT "line .");
		value = search;
		jlstadd_back(brace, append);
	}
	if (*value)
	{
		append = jlstnew(jstrdup(value));
		mini_assert(append != NULL && append->content != NULL, \
			ASSERT "line .");
		jlstadd_back(brace, append);
	}
}

char	*expand_brace(t_lst *brace)
{
	bool	ret;
	char	*middle;
	t_lst	*origin;

	middle = NULL;
	origin = brace;
	ret = jstrappend(&middle, (char *)(brace->content));
	mini_assert(ret, ASSERT "line .");
	while (brace->next)
	{
		brace = brace->next;
		ret =jstrappend(&middle, "\\ ");
		mini_assert(ret, ASSERT "line .");
		ret = jstrappend(&middle, (char *)(brace->content));
		mini_assert(ret, ASSERT "line .");
	}
	jlstclear(&origin, jfree);
	return (middle);
}

char	*expand_middle(char *input, char *iter, char *last, t_rb *envmap)
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
		ASSERT "line .");
	jfree((void **)(&value));
	return (expand_brace(brace));
}

char	*expand_last(char *iter)
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

char	*expand(char *input, t_rb *envmap, bool d_quote)
{
	char	*iter;

	if (!input)
		return (NULL);
	iter = input;
	while (*iter)
	{
		if (*iter == '\"')
			d_quote = !d_quote;
		else if (*iter == '\'' && !d_quote)
			iter = jstrchr(iter + 1, '\'');
		else if (*iter == '<' && *(iter + 1) == '<' && !d_quote)
		{
			iter += 2;
			while (*iter && jisspace(*iter))
				++iter;
			while (*iter && !jisspace(*iter))
				++iter;
		}
		if (*iter == '$')
			return (expand_internal(input, iter, envmap, d_quote));
		++iter;
	}
	return (input);
}

char	*tokenize_internal(char *input, char *begin, char *end, t_lst **chunks)
{
	char	*token;
	t_lst	*temp;

	token = jsubstr(input, begin - input, end - begin + 1);
	temp = jlstnew(token);
	mini_assert(token != NULL && temp != NULL, \
		ASSERT "line .");
	jlstadd_back(chunks, temp);
	return (end + 1);
}

void	tokenize(char *input, t_lst **chunks)
{
	char	*begin;
	char	*end;

	begin = input;
	while (*begin)
	{
		while (jisspace(*begin))
			++begin;
		end = begin;
		while (!jstrchr(" ><|", *begin))
		{
			if (jstrchr("\'\"", *end))
				end = jstrchr(end + 1, *end);
			if (jstrchr(" ><|", *(end + 1)) && *end != '\\')
				break ;
			++end;
		}
		if (jstrchr("><", *begin) && *begin && *begin == *(begin + 1))
			++end;
		if (*begin)
			begin = tokenize_internal(input, begin, end, chunks);
	}
}

void	loop(char *input, t_lst *chunks, t_as *syntax, t_rb *envmap)
{
	(void)syntax;
	while (true)
	{
		jfree((void **)(&input));
		input = readline("hi$ ");
		mini_assert(input != NULL, \
			ASSERT "line .");
		if (!jstrlen(input))
			continue ;
		add_history(input);
		input = expand(input, envmap, false);
		printf("input : %s\n\n", input);
		mini_assert(input != NULL, \
			ASSERT "line .");
		tokenize(input, &chunks);
		mini_assert(chunks != NULL, \
			ASSERT "line .");
		jlstshow(chunks);
		// syntax = as_init(chunks);
		// as_exec(syntax, envmap);
		// as_free(syntax);
		jlstclear(&chunks, jfree);
	}
}

int main(int argc, char **argv, char **envp)
{
	char	*input;
	t_lst	*chunks;
	t_as	*syntax;
	t_rb	*envmap;

	(void)argc;
	(void)argv;
	input = NULL;
	chunks = NULL;
	syntax = NULL;
	envmap = rb_init(compare);
	pair(envmap, envp);
	loop(input, chunks, syntax, envmap);
	return (VALID);
}
