/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_file_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:12:41 by jseo              #+#    #+#             */
/*   Updated: 2021/04/18 13:12:42 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	e_file_parsing(void)
{
	errno = 79;
	perror("ERROR SPEC: file parsing\nerrno 79");
	printf("Error\n");
	exit(INVALID);
}
