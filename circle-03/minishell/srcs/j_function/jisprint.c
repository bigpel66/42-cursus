/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jisprint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 22:03:48 by jseo              #+#    #+#             */
/*   Updated: 2021/12/26 22:19:03 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_function.h"

bool	jisprint(int c)
{
	return (c >= 32 && c <= 126);
}
