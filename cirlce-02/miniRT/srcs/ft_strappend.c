/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:23:54 by jseo              #+#    #+#             */
/*   Updated: 2021/04/18 13:29:58 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*ft_strappend(char *s1, char *s2)
{
	char	*s;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (s1);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	s = (char *)malloc(i + j + 1);
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1, i + 1);
	ft_strlcpy(s + i, s2, j + 1);
	free(s1);
	return (s);
}
