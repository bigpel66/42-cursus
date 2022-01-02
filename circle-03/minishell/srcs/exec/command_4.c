/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:05:19 by jseo              #+#    #+#             */
/*   Updated: 2022/01/02 11:37:55 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** arrange ()			- Trim Quotes on the Given String
**
** return				- void
** chunk				- String to be Quotes Trimmed
** ict					- Please Check the Structure on Details Header
*/

void	arrange(char *chunk)
{
	size_t		*ict;

	jcalloc((void **)(&ict), 3, sizeof(size_t));
	mini_assert(ict != NULL, \
		MASSERT "line .");
	while (ict[INDEX] < jstrlen(chunk))
	{
		if (chunk[ict[INDEX]] == '\'' && ict[TYPE] == OFF)
			ict[TYPE] = SINGLE;
		else if (chunk[ict[INDEX]] == '\'' && ict[TYPE] == SINGLE)
			ict[TYPE] = OFF;
		else if (chunk[ict[INDEX]] == '\"' && ict[TYPE] == OFF)
			ict[TYPE] = DOUBLE;
		else if (chunk[ict[INDEX]] == '\"' && ict[TYPE] == DOUBLE)
			ict[TYPE] = OFF;
		else if (chunk[ict[INDEX]] != '\'' && chunk[ict[INDEX]] != '\"')
			chunk[ict[CONTENT]++] = chunk[ict[INDEX]];
		else if (chunk[ict[INDEX]] == '\"' && ict[TYPE] == SINGLE)
			chunk[ict[CONTENT]++] = '\"';
		else if (chunk[ict[INDEX]] == '\'' && ict[TYPE] == DOUBLE)
			chunk[ict[CONTENT]++] = '\'';
		++ict[INDEX];
	}
	chunk[ict[CONTENT]] = '\0';
	jfree((void **)(&ict));
}
