/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_element_identifier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:12:49 by jseo              #+#    #+#             */
/*   Updated: 2021/04/21 19:58:29 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	e_element_identifier(void **ptr, t_scene *rt)
{
	errno = 0;
	perror("Type: Element identifier\nerrno 0");
	printf("Error\n");
	free_ptr(ptr);
	free_scene(rt);
	exit(INVALID);
}
