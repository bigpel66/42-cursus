/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jstrrchr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:07:53 by jseo              #+#    #+#             */
/*   Updated: 2022/01/05 12:10:25 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jfunction.h"

char	*jstrrchr(const char *s, int c)
{
	size_t	i;

	i = jstrlen(s) + 1;
	while (i--)
		if (s[i] == c)
			return ((char *)s + i);
	return (NULL);
}
