/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_element_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:12:41 by jseo              #+#    #+#             */
/*   Updated: 2021/04/21 19:58:18 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	e_element_dup(void **ptr)
{
	errno = 0;
	perror("Type: Element duplicate\nerrno 0");
	printf("Error\n");
	free_ptr(ptr);
	exit(INVALID);
}
