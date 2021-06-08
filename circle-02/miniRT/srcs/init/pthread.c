/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 17:46:32 by jseo              #+#    #+#             */
/*   Updated: 2021/05/07 17:46:34 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	p_init(t_p *arg, void *t, void *p, t_mlx *m)
{
	arg->t = t;
	arg->p = p;
	arg->m = m;
}

void	p_update(t_p *arg, int i, int x, t_mux *l)
{
	arg->i = i;
	arg->x = x;
	arg->l = l;
}
