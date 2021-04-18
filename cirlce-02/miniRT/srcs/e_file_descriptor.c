/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_file_descriptor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:12:29 by jseo              #+#    #+#             */
/*   Updated: 2021/04/18 13:12:30 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	e_file_descriptor(void)
{
	errno = 9;
	perror("ERROR SPEC: file open\nerrno 9");
	printf("\nError\n");
	exit(INVALID);
}
