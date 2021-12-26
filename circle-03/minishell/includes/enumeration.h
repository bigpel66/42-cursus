/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enumeration.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:34:38 by jseo              #+#    #+#             */
/*   Updated: 2021/12/26 21:58:49 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMERATION_H
# define ENUMERATION_H

/*
** =============================================================================
** Enum Type Definitions
** =============================================================================
*/

typedef enum e_exit
{
	VALID = 0,
	GENERAL = 1,
	BUILTIN = 2,
	NOTEXECUTABLE = 126,
	NOTFOUND = 127,
	ARGUMENT = 128,
	INTERRUPT = 130,
	RANGE = 255,
}			t_exit;

#endif
