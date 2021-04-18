/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_window.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:13:00 by jseo              #+#    #+#             */
/*   Updated: 2021/04/18 13:13:01 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	e_window(void)
{
	errno = 49;
	perror("ERROR SPEC: creation of window\nerrno 49");
	printf("\nError\n");
	exit(INVALID);
}
