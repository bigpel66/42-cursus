/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:00:59 by jseo              #+#    #+#             */
/*   Updated: 2022/01/01 12:38:59 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** expand ()			- Expand the Input String which Starts with $
**
** return				- Expanded String
** input				- Variable for a User Input
** envmap				- Variable for Maps the Environment Variables
** d_quote				- Whether the Input Braced by Double Quotes
** iter					- Variable for Iterating the Input
*/

char	*expand(char *input, t_rb *envmap, bool d_quote)
{
	char	*iter;

	if (input == NULL)
		return (NULL);
	iter = input;
	while (*iter)
	{
		if (*iter == '\"')
			d_quote = !d_quote;
		else if (*iter == '\'' && !d_quote)
			iter = jstrchr(iter + 1, '\'');
		else if (*iter == '<' && *(iter + 1) == '<' && !d_quote)
		{
			iter += 2;
			while (*iter && jisspace(*iter))
				++iter;
			while (*iter && !jisspace(*iter))
				++iter;
		}
		if (*iter == '$')
			return (expand_internal(input, iter, envmap, d_quote));
		if (*iter)
			++iter;
	}
	return (input);
}
