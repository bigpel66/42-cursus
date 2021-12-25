/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:41:44 by jseo              #+#    #+#             */
/*   Updated: 2021/12/26 01:32:15 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* rb tree test case */
// t_rb *rb = rb_init(compare);
// rb_insert(rb, jstrdup("a"), jstrdup("1"));
// rb_insert(rb, jstrdup("b"), jstrdup("2"));
// rb_insert(rb, jstrdup("x4444"), jstrdup("3"));
// rb_insert(rb, jstrdup("x22"), jstrdup("4"));
// rb_insert(rb, jstrdup("x3"), jstrdup("5"));
// rb_insert(rb, jstrdup("x2"), jstrdup("5"));
// rb_insert(rb, jstrdup("x"), jstrdup("51"));
// print_tree(rb);
// rb_delete(rb, "b");
// rb_delete(rb, "x2");
// rb_delete(rb, "x");
// rb_delete(rb, "a");
// print_tree(rb);
// rb_delete(rb, "x4444");
// rb_delete(rb, "x3");
// rb_delete(rb, "x22");
// print_tree(rb);

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

char	*expand_internal(char *input, char *iter, t_rb *envmap, bool d_quote)
{
	// implement
	return (input);
}

char	*envmap_expand(char *input, t_rb *envmap, bool d_quote)
{
	char	*iter;

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
			return expand_internal(input, iter, envmap, d_quote);
		++iter;
	}
	return (input);
}

void	shell_loop(char *input, char **token, t_as *parse, t_rb *envmap)
{
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
		tokenize(input, &token);
		mini_assert(token != NULL, \
			ASSERT "line .");
		parse = as_init(token);
		as_exec(parse, envmap);
		as_free(parse);
		detokenize(&token);
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
