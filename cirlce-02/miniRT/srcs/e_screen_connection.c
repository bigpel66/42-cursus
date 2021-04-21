/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_screen_connection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:12:56 by jseo              #+#    #+#             */
/*   Updated: 2021/04/21 19:59:21 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	e_screen_connection(t_scene *rt)
{
	errno = 49;
	perror("Type: Creation of screen connection\nerrno 49");
	printf("\nError\n");
	free_scene(rt);
	exit(INVALID);
}
