/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:01:52 by jseo              #+#    #+#             */
/*   Updated: 2022/01/01 12:39:03 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** tokenize_internal ()	- Tokenize Logic
**
** return				- The Next Address of Generated Token
** input				- Variable for a User Input
** begin				- Begin Address of Tokenization
** end					- End Address of Tokenization
** chunks				- Variable for Tokens of User Input
** token				- Generated Token
** temp					- Temp Data Structure to Append on the Chunks
*/

char	*tokenize_internal(char *input, char *begin, char *end, t_lst **chunks)
{
	char	*token;
	t_lst	*temp;

	token = jsubstr(input, begin - input, end - begin + 1);
	temp = jlstnew(token);
	mini_assert(token != NULL && temp != NULL, \
		MASSERT "(toekn != NULL && temp != NULL), " \
		TOKENIZE_INTERNAL MTOKENIZE_FILE "line 34.");
	jlstadd_back(chunks, temp);
	return (end + 1);
}

/*
** tokenize ()			- Tokenize User Input
**
** return				- void
** input				- Variable for a User Input
** chunks				- Variable for Tokens of User Input
** begin				- Begin Address of Tokenization
** end					- End Address of Tokenization
*/

void	tokenize(char *input, t_lst **chunks)
{
	char	*begin;
	char	*end;

	begin = input;
	while (*begin)
	{
		while (jisspace(*begin))
			++begin;
		end = begin;
		while (*end && !jstrchr(" ><|", *begin))
		{
			if (jstrchr("\'\"", *end))
				end = jstrchr(end + 1, *end);
			if (jstrchr("><|", *(end + 1))
				|| (*end != '\\' && *(end + 1) == ' '))
				break ;
			++end;
		}
		if (!*end)
			--end;
		if (*begin && *begin == *(begin + 1) && jstrchr("><", *begin))
			++end;
		if (*begin)
			begin = tokenize_internal(input, begin, end, chunks);
	}
}
