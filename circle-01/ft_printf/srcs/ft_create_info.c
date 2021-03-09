/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:25:18 by jseo              #+#    #+#             */
/*   Updated: 2021/03/09 14:22:43 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_info	*ft_create_info(t_info *i)
{
	if (!(i = (t_info *)malloc(sizeof(t_info))))
		return (NULL);
	ft_memset(i, 0, sizeof(t_info));
	return (i);
}
