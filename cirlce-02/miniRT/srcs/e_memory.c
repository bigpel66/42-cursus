/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_memory.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:12:49 by jseo              #+#    #+#             */
/*   Updated: 2021/04/18 23:14:40 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	e_memory(void)
{
	errno = 12;
	perror("Type: Memory allocation\nerrno 12");
	printf("\nError\n");
	exit(INVALID);
}
