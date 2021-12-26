/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jwordlen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 22:09:04 by jseo              #+#    #+#             */
/*   Updated: 2021/12/26 22:09:32 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_function.h"

size_t	jwordlen(const char *s, bool (*cmp)(int))
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (!cmp(*s))
		{
			++cnt;
			while (*s && !cmp(*s))
				++s;
		}
		else
			++s;
	}
	return (cnt);
}
