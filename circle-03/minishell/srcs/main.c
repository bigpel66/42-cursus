/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:41:44 by jseo              #+#    #+#             */
/*   Updated: 2021/12/25 00:20:50 by jseo             ###   ########.fr       */
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

void	make_envmap(t_rb *envmap, char **envp)
{
	char	*value;

	while (*envp)
	{
		value = jstrchr(*envp, '=');
		*value++ = '\0';
		rb_insert(envmap, jstrdup(*envp++), jstrdup(value));
	}
}

void	shell_loop(char *input, char **token, t_as *parse, t_rb *envmap)
{
	(void)input;
	(void)token;
	(void)parse;
	(void)envmap;
	while (1)
		;
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
	make_envmap(envmap, envp);
	shell_loop(input, token, parse, envmap);
	return (VALID);
}
