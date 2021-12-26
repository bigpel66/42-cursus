/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:41:44 by jseo              #+#    #+#             */
/*   Updated: 2021/12/26 17:03:31 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*envmap_expand(char *input, t_rb *envmap, bool d_quote);

void	mini_assert(bool condition, char *context)
{
	if (condition)
		return ;
	jputendl(context, STDERR_FILENO);
	exit(GENERAL);
}

void	envmap_init(t_rb *envmap, char **envp)
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

char	*expand_middle(char *input, char *iter, char *last, t_rb *envmap)
{
	char	*key;
	char	*value;

	if (last - iter == 1)
		return (jstrdup("?"));
	key = jsubstr(input, iter - input + 1, last - iter - 1);
	value = get_value(envmap, key);
	if (!value)
		value = "";
	jfree((void **)(&key));
	return (jstrdup(value));
}

char	*expand_last(char *iter)
{

	if (jstrchr("?$#*", *iter))
		++iter;
	else
		while (!jstrchr(" ><\'\"|?$", *iter))
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
	latter = envmap_expand(last, envmap, d_quote);
	jfree((void **)(&middle));
	jfree((void **)(&first));
	jfree((void **)(&input));
	input = jstrjoin(former, latter);
	jfree((void **)(&latter));
	jfree((void **)(&former));
	return (input);
}

char	*envmap_expand(char *input, t_rb *envmap, bool d_quote)
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

void	shell_loop(char *input, char **token, t_as *parse, t_rb *envmap)
{
	(void)token;
	(void)parse;
	while (true)
	{
		jfree((void **)(&input));
		input = readline("hi$ ");
		mini_assert(input != NULL, \
			ASSERT "line .");
		if (!jstrlen(input))
			continue ;
		add_history(input);
		input = envmap_expand(input, envmap, false);
		printf("input : %s\n\n", input);
		// mini_assert(input != NULL, \
			// ASSERT "line .");
		// tokenize(input, &token);
		// mini_assert(token != NULL, \
		// 	ASSERT "line .");
		// parse = as_init(token);
		// as_exec(parse, envmap);
		// as_free(parse);
		// detokenize(&token);
	}
}

int main(int argc, char **argv, char **envp)
{
	char	*input;
	char	**token;
	t_as	*parse;
	t_rb	*envmap;

	(void)argc;
	(void)argv;
	input = NULL;
	token = NULL;
	parse = NULL;
	envmap = rb_init(compare);
	envmap_init(envmap, envp);
	shell_loop(input, token, parse, envmap);
	return (VALID);
}
