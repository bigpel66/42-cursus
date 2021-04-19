/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdouble.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 23:15:44 by jseo              #+#    #+#             */
/*   Updated: 2021/04/19 10:52:06 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	sdouble(char **line, double *v1, double *v2, double *v3)
{
	printf("%s\n", *line);
	printf("%lf\n", *v1);
	printf("%lf\n", *v2);
	printf("%lf\n", *v3);
	return (TRUE);
}
