/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_element_identifier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:12:49 by jseo              #+#    #+#             */
/*   Updated: 2021/04/22 13:46:46 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	e_element_identifier(void **ptr, t_scene *rt)
{
	errno = 79;
	perror("Type: Element identifier\nerrno 79");
	printf("Error\n");
	free_ptr(ptr);
	free_scene(rt);
	exit(INVALID);
}
