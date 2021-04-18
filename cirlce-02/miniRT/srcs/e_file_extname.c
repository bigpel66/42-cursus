/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_file_extname.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:12:34 by jseo              #+#    #+#             */
/*   Updated: 2021/04/18 13:12:36 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	e_file_extname(void)
{
	errno = 79;
	perror("ERROR SPEC: file extname\nerrno 79");
	printf("Error\n");
	exit(INVALID);
}
