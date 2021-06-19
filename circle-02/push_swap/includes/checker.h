/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:34:25 by jseo              #+#    #+#             */
/*   Updated: 2021/06/19 16:34:25 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "shared.h"

void		print_stacks(t_ps **ps);
bool		yield(t_ps **ps);
void		do_push(t_ps **ps, char *line, size_t len);
void		do_rotate(t_ps **ps, char *line, size_t len);
void		do_rrotate(t_ps **ps, char *line, size_t len);
void		do_swap(t_ps **ps, char *line, size_t len);
#endif
