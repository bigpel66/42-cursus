/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_screen_connection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:12:56 by jseo              #+#    #+#             */
/*   Updated: 2021/04/18 13:12:58 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	e_screen_connection(void)
{
	errno = 49;
	perror("ERROR SPEC: creation of screen connection\nerrno 49");
	printf("\nError\n");
	exit(INVALID);
}
