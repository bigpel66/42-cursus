/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:41:44 by jseo              #+#    #+#             */
/*   Updated: 2021/12/24 15:09:45 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;
	t_rb *rb = rb_init(compare);
	rb_insert(rb, "a", "1");
	rb_insert(rb, "b", "2");
	rb_insert(rb, "x4444", "3");
	rb_insert(rb, "x22", "4");
	rb_insert(rb, "x3", "5");
	rb_insert(rb, "x2", "5");
	rb_insert(rb, "x", "51");
	// rb_insert(rb, "c", "3");
	// rb_insert(rb, "a", "1");
	// rb_insert(rb, "abb", "2");
	// rb_insert(rb, "bbbb", "2");
	// rb_insert(rb, "bxx", "2");
	// rb_insert(rb, "avvcx", "3");
	// rb_insert(rb, "d", "3");
	// rb_insert(rb, "g", "3");
	// rb_insert(rb, "z", "3");
	// rb_insert(rb, "ggggg", "3");
	// rb_insert(rb, "ggg5", "3");
	// rb_insert(rb, "x", "3");
	print_tree(rb);
	return (VALID);
}
