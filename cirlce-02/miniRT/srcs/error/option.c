/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:10:27 by jseo              #+#    #+#             */
/*   Updated: 2021/04/22 17:10:28 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	e_option()
{
	errno = 22;
	perror("Type: Input option\nerrno 22");
	write(STDERR_FILENO, "ERROR\n", 6);
	exit(INVALID);
}
