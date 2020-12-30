/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:41:01 by jseo              #+#    #+#             */
/*   Updated: 2020/12/30 12:38:27 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!s1 || !s2 || !(s = (char *)malloc(i + j + 1)))
		return (NULL);
	ft_strlcpy(s, s1, i + 1);
	ft_strlcat(s, s2, i + j + 1);
	return (s);
}
