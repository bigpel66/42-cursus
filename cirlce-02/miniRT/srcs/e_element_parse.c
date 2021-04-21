/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_element_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:12:41 by jseo              #+#    #+#             */
/*   Updated: 2021/04/21 19:58:53 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	e_element_parse(void **ptr, t_scene *rt)
{
	errno = 79;
	perror("Type: Element parse\nerrno 79");
	printf("Error\n");
	free_ptr(ptr);
	free_scene(rt);
	exit(INVALID);
}
