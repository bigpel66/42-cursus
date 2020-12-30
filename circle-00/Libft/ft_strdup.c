/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:48:19 by jseo              #+#    #+#             */
/*   Updated: 2020/12/30 12:00:03 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*buf;

	len = ft_strlen(s);
	if (!(buf = (char *)malloc(len + 1)))
		return (NULL);
	ft_strlcpy(buf, s, len + 1);
	return (buf);
}
