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

/*
** =============================================================================
** Dependencies
** =============================================================================
*/

# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

/*
** =============================================================================
** Macro Constants
** =============================================================================
*/

# define VALID		0
# define INVALID	1

/*
** =============================================================================
** Type Definitions
** =============================================================================
*/

typedef struct		s_list
{
	int				v;
	struct s_list	*p;
	struct s_list	*n;
}					t_list;

typedef struct		s_set
{
	int				o;
	int				v;
	char			c;
	struct s_set	*l;
	struct s_set	*r;
	struct s_set	*p;
}					t_set;

typedef struct		s_pred
{
	int				dst_index;
	int				src_index;
	int				sort_inst;
	int				total_inst;
}					t_pred;

typedef struct		s_ps
{
	t_list			*ah;
	t_list			*at;
	t_list			*bh;
	t_list			*bt;
	int				min;
	int				max;
	int				al;
	int				bl;
	int				ol;
	int				os;
	int				os_pos;
	int				of;
	int				of_pos;
}					t_ps;

/*
** =============================================================================
** Context Functions
** =============================================================================
*/

bool				check(int ac, char **av, t_set **s, t_ps **ps);
void				prerequisite(t_ps **ps);
void				print_stacks(t_ps **ps);
void				exit_invalid(t_ps **ps);
void				exit_valid(t_ps **ps);

/*
** =============================================================================
** Instruction Functions
** =============================================================================
*/

void				inst_pa(t_ps **ps, char *cmd);
void				inst_pb(t_ps **ps, char *cmd);
void				inst_ra(t_ps **ps, char *cmd);
void				inst_rb(t_ps **ps, char *cmd);
void				inst_rr(t_ps **ps, char *cmd);
void				inst_rra(t_ps **ps, char *cmd);
void				inst_rrb(t_ps **ps, char *cmd);
void				inst_rrr(t_ps **ps, char *cmd);
void				inst_sa(t_ps **ps, char *cmd);
void				inst_sb(t_ps **ps, char *cmd);
void				inst_ss(t_ps **ps, char *cmd);

/*
** =============================================================================
** Library Functions
** =============================================================================
*/

bool				jatoi(char **s, int *v);
bool				jcalloc(void **ptr, size_t cnt, size_t n);
void				jfree(void **ptr);
bool				jisdigit(int c);
bool				jisspace(int c);
void				jlstclear(t_list *head, t_list *tail);
bool				jlstempty(t_list *lst);
t_list				*jlstlast(t_list *lst);
bool				jlstnew(t_list **lst, int v);
void				jlstshow_cw(t_list *lst);
void				jlstshow_ccw(t_list *lst);
size_t				jlstsize(t_list *lst);
void				jmemset(void *s, int c, size_t n);
size_t				jnumlen(int v);
void				jputchar(char c, int fd);
void				jputnbr(int n, int fd);
void				jputstr(char *s, int fd);
size_t				jstrlen(const char *s);
int					jstrncmp(const char *s1, const char *s2, size_t n);
void				jstrtrim(char **s);

/*
** =============================================================================
** Set Functions
** =============================================================================
*/

void				set_alloc_root(t_set **s, t_set **n);
void				set_alloc_rest(t_set **s, t_set **n);
void				set_red_color(t_set **n, t_set *u);
void				set_llb_color(t_set **s, t_set **n);
void				set_lrb_color(t_set **s, t_set **n);
void				set_rlb_color(t_set **s, t_set **n);
void				set_rrb_color(t_set **s, t_set **n);
void				set_delete(t_set **s);
void				set_inorder(t_set **s);
bool				set_insert(t_set **s, int v);
void				set_left_rotate(t_set **s, t_set **n);
void				set_right_rotate(t_set **s, t_set **n);

/*
** =============================================================================
** Predicate Functions
** =============================================================================
*/

void				pre_init(t_pred *pred);
void				pred_find(t_ps **ps, t_pred *pred, int v, int i);
void				pred_swap(t_pred *tmp, t_pred *min);
void				pred_exec(t_ps **ps, t_pred *min);

/*
** =============================================================================
** Stack Functions
** =============================================================================
*/

int					stack_min(t_ps **ps);
void				stack_len(t_ps **ps);
void				stack_series(t_ps **ps);
void				stack_correction(t_ps **ps, int i);

/*
** =============================================================================
** Solution Functions
** =============================================================================
*/

void				a_to_b(t_ps **ps);
void				b_to_a(t_ps **ps);
void				yield(t_ps **ps);

/*
** =============================================================================
** Test Functions
** =============================================================================
*/

void				iter(t_ps **ps, int e, void (*f)(t_ps **, char *), char *s);
void				test_push(t_ps **ps);
void				test_rotate(t_ps **ps);
void				test_rrotate(t_ps **ps);
void				test_swap(t_ps **ps);

#endif
