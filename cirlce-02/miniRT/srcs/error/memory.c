/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:10:27 by jseo              #+#    #+#             */
/*   Updated: 2021/04/23 16:45:29 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	e_memory_alloc(t_mlx *m)
{
	errno = 12;
	perror("Type: Memory allocation\nerrno 12");
	write(STDERR_FILENO, "ERROR\n", 6);
	mlx_free(m);
	exit(INVALID);
}
