/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_file_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:12:29 by jseo              #+#    #+#             */
/*   Updated: 2021/04/21 19:59:15 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	e_file_read(void **ptr, t_scene *rt)
{
	errno = 45;
	perror("Type: File read\nerrno 45");
	printf("Error\n");
	free_ptr(ptr);
	free_scene(rt);
	exit(INVALID);
}
