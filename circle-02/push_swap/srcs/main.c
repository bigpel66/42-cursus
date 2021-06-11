/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:01:05 by jseo              #+#    #+#             */
/*   Updated: 2021/06/11 20:33:52 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_ps	*ps;

	ps = NULL;
	if (!jcalloc((void **)(&ps), 1, sizeof(t_ps)) ||
		!args_check(argc, argv, &ps) || !args_unique(&ps))
		exit_invalid(&ps);
	else
	{
		if (!args_sorted(&ps))
		{
			/*
			// push testing
			inst_pb(&ps);
			inst_pb(&ps);
			inst_pb(&ps);
			printf("%d %d %d\n", ps->bh->v, ps->bh->n->v, ps->bh->n->n->v);
			printf("%zu %zu\n", jlstsize(ps->ah), jlstsize(ps->bh));
			inst_pa(&ps);
			inst_pa(&ps);
			printf("%d\n %d %d\n", ps->bh->v, ps->ah->p->v, ps->ah->p->p->v);
			printf("%zu %zu\n", jlstsize(ps->ah), jlstsize(ps->bh));
			inst_pa(&ps);
			if (jlstempty(ps->bh))
				printf("empty!");
			*/
			/*
			// swap testing
			inst_sa(&ps);
			printf("%d %d %d %d\n",
					ps->ah->v,
					ps->ah->n->v,
					ps->ah->n->n->v,
					ps->ah->p->p->v);
			printf("%d\n", ps->at->v);
			inst_pb(&ps);
			inst_pb(&ps);
			inst_sb(&ps);
			if (jlstempty(ps->bh))
				printf("empty");
			else
			{
				printf("%d %d %d %d\n",
						ps->bh->v,
						ps->bh->n->v,
						ps->bh->n->n->v,
						ps->bh->p->p->v);
				printf("%d\n", ps->bt->v);
			}
			*/
		}
		else
			printf("sorted\n");
	}
	exit_valid(&ps);
}
