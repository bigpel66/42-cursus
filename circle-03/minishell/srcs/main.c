/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:41:44 by jseo              #+#    #+#             */
/*   Updated: 2021/12/22 18:36:56 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	int i = -1;
	while (*envp != NULL && ++i >= 0)
	{
		printf("%d: %s\n", i, *envp++);
	}
	return (VALID);
}
