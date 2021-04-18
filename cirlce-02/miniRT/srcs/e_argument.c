/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_argument.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:12:23 by jseo              #+#    #+#             */
/*   Updated: 2021/04/18 13:12:25 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	e_argument(void)
{
	errno = 22;
	perror("ERROR SPEC: input argc\nerrno 22");
	printf("\nError\n");
	exit(INVALID);
}
