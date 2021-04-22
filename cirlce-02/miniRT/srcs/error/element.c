/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:12:41 by jseo              #+#    #+#             */
/*   Updated: 2021/04/22 17:25:21 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	e_element_memory(t_scene *rt)
{
	errno = 12;
	perror("Type: Element memory allocation\nerrno 12");
	write(STDERR_FILENO, "ERROR\n", 6);
	free_scene(rt);
	exit(INVALID);
}

void	e_element_dup(void **ptr, int fd)
{
	errno = 79;
	perror("Type: Element duplicate\nerrno 79");
	write(STDERR_FILENO, "ERROR\n", 6);
	free_ptr(ptr);
	close(fd);
	exit(INVALID);
}

void	e_element_parse(void **ptr, t_scene *rt, int fd)
{
	errno = 79;
	perror("Type: Element parse\nerrno 79");
	write(STDERR_FILENO, "ERROR\n", 6);
	free_ptr(ptr);
	free_scene(rt);
	close(fd);
	exit(INVALID);
}

void	e_element_identifier(void **ptr, t_scene *rt, int fd)
{
	errno = 79;
	perror("Type: Element identifier\nerrno 79");
	write(STDERR_FILENO, "ERROR\n", 6);
	free_ptr(ptr);
	free_scene(rt);
	close(fd);
	exit(INVALID);
}
