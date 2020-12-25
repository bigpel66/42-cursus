/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:48:19 by jseo              #+#    #+#             */
/*   Updated: 2020/12/25 20:11:51 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*buf;

	i = -1;
	if (!(buf = (char *)malloc(ft_strlen(s) + 1)))
		return (NULL);
	while (s[++i])
		buf[i] = s[i];
	buf[i] = '\0';
	return (buf);
}
