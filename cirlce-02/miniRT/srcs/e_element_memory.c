/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_element_memory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:12:49 by jseo              #+#    #+#             */
/*   Updated: 2021/04/21 19:58:40 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	e_element_memory(t_scene *rt)
{
	errno = 12;
	perror("Type: Element memory allocation\nerrno 12");
	printf("Error\n");
	free_scene(rt);
	exit(INVALID);
}
