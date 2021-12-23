/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:41:44 by jseo              #+#    #+#             */
/*   Updated: 2021/12/23 19:18:30 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;
	t_rb *rb = NULL;
	rb = rb_insert(rb, "c", "3");
	rb = rb_insert(rb, "a", "1");
	rb = rb_insert(rb, "abb", "2");
	rb = rb_insert(rb, "bbbb", "2");
	rb = rb_insert(rb, "bxx", "2");
	rb = rb_insert(rb, "avvcx", "3");
	rb = rb_insert(rb, "d", "3");
	rb = rb_insert(rb, "g", "3");
	rb = rb_insert(rb, "z", "3");
	rb = rb_insert(rb, "ggggg", "3");
	rb = rb_insert(rb, "ggg5", "3");
	rb = rb_insert(rb, "x", "3");
	printf("Before\n");
	rb_order(rb, INORDER);

	t_rb *x = rb_search(rb, "x");
	rb = rb_delete(rb, x);
	x = rb_search(rb, "a");
	rb = rb_delete(rb, x);

	printf("After\n");
	rb_order(rb, INORDER);
	// int i = -1;
	// while (*envp != NULL && ++i >= 0)
	// {
	// 	printf("%d: %s\n", i, *envp++);
	// }
	return (VALID);
}
