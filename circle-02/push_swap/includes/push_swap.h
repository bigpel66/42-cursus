/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:01:32 by jseo              #+#    #+#             */
/*   Updated: 2021/06/17 15:51:21 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "shared.h"

/*
** =============================================================================
** Type Definitions
** =============================================================================
*/

typedef struct		s_pred
{
	int				dst_index;
	int				src_index;
	int				dst_rot;
	int				src_rot;
	int				total_inst;
	bool			is_former;
	bool			is_coordinated;
}					t_pred;

typedef struct		s_base
{
	int				len;
	int				s_index;
	int				f_index;
}					t_base;

/*
** =============================================================================
** Predicate Functions
** =============================================================================
*/

void				pred_init(t_pred *pred);
void				pred_find(t_ps **ps, t_pred *pred, int val, int pos);
void				pred_swap(t_pred *tmp, t_pred *min);
void				pred_exec(t_ps **ps, t_pred *min);

/*
** =============================================================================
** Stack Functions
** =============================================================================
*/

int					find_minimum(t_ps **ps);
int					find_normalize(int *val, int len);
void				stack_len(t_ps **ps);
void				stack_series(t_ps **ps, t_base *base);
void				stack_correction(t_ps **ps, int pos);

/*
** =============================================================================
** Solution Functions
** =============================================================================
*/

void				a_to_b(t_ps **ps, t_base *base);
void				b_to_a(t_ps **ps);
void				yield(t_ps **ps);

#endif
