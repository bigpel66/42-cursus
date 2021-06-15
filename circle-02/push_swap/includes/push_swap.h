/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:01:32 by jseo              #+#    #+#             */
/*   Updated: 2021/06/14 11:37:28 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
** =============================================================================
** Dependencies
** =============================================================================
*/

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>

/*
** =============================================================================
** Macro Constants
** =============================================================================
*/

# define VALID				0
# define INVALID			1

# define PA					0
# define PB					1
# define RA					2
# define RB					3
# define RR					4
# define RRA				5
# define RRB				6
# define RRR				7
# define SA					8
# define SB					9
# define SS					10

/*
** =============================================================================
** Type Definitions
** =============================================================================
*/

typedef struct			s_list
{
	int					v;
	struct s_list		*p;
	struct s_list		*n;
}						t_list;

typedef struct			s_set
{
	int					o;
	int					v;
	char				c;
	struct s_set		*l;
	struct s_set		*r;
	struct s_set		*p;
}						t_set;

typedef struct			s_map
{
	char				*k;
	char				*v;
	char				c;
	struct s_map		*l;
	struct s_map		*r;
	struct s_map		*p;
}						t_map;

typedef struct			s_ps
{
	t_list				*ah;
	t_list				*at;
	t_list				*bh;
	t_list				*bt;
	t_set				*s;
	t_map				*m;
	int					cnt;
	int					min;
	int					max;
}						t_ps;

typedef struct			s_m
{
	t_set				*a;
	t_set				*b;
	int					cnt;
}						t_m;

/*
** =============================================================================
** Context Functions
** =============================================================================
*/

bool					args_check(int argc, char **argv, t_ps **ps);
bool					args_sorted(t_ps **ps);
void					print_stacks(t_ps **ps);
void					exit_invalid(t_ps **ps);
void					exit_valid(t_ps **ps);

/*
** =============================================================================
** Instruction Functions
** =============================================================================
*/

void					inst_pa(t_ps **ps);
void					inst_pb(t_ps **ps);
void					inst_ra(t_ps **ps);
void					inst_rb(t_ps **ps);
void					inst_rr(t_ps **ps);
void					inst_rra(t_ps **ps);
void					inst_rrb(t_ps **ps);
void					inst_rrr(t_ps **ps);
void					inst_sa(t_ps **ps);
void					inst_sb(t_ps **ps);
void					inst_ss(t_ps **ps);

/*
** =============================================================================
** Library Functions
** =============================================================================
*/

bool					jatoi(char **s, int *v);
bool					jcalloc(void **ptr, size_t cnt, size_t n);
void					jfree(void **ptr);
bool					jisdigit(int c);
bool					jisspace(int c);
void					jlstclear(t_list **lst);
void					jlstdelone(t_list **lst);
bool					jlstempty(t_list *lst);
t_list					*jlstlast(t_list *lst);
bool					jlstnew(t_list **lst, int v);
void					jlstshow(t_list *lst);
size_t					jlstsize(t_list *lst);
void					jmemset(void *s, int c, size_t n);
size_t					jnumlen(int v);
void					jputchar(char c, int fd);
void					jputnbr(int n, int fd);
void					jputstr(char *s, int fd);
size_t					jstrlen(const char *s);
int						jstrncmp(const char *s1, const char *s2, size_t n);
void					jstrtrim(char **s);

/*
** =============================================================================
** Map Functions
** =============================================================================
*/

void					map_alloc_root(t_map **m, t_map **n);
void					map_alloc_rest(t_map **m, t_map **n);
void					map_red_color(t_map **n, t_map *u);
void					map_llb_color(t_map **m, t_map **n);
void					map_lrb_color(t_map **m, t_map **n);
void					map_rlb_color(t_map **m, t_map **n);
void					map_rrb_color(t_map **m, t_map **n);
void					map_delete(t_map **m);
void					map_inorder(t_map **m);
bool					map_insert(t_map **m, char *k, char *v);
void					map_left_rotate(t_map **m, t_map **n);
void					map_right_rotate(t_map **m, t_map **n);

/*
** =============================================================================
** Set Functions
** =============================================================================
*/

void					set_alloc_root(t_set **s, t_set **n);
void					set_alloc_rest(t_set **s, t_set **n);
void					set_red_color(t_set **n, t_set *u);
void					set_llb_color(t_set **s, t_set **n);
void					set_lrb_color(t_set **s, t_set **n);
void					set_rlb_color(t_set **s, t_set **n);
void					set_rrb_color(t_set **s, t_set **n);
void					set_delete(t_set **s);
void					set_inorder(t_set **s);
bool					set_insert(t_set **s, int v);
void					set_left_rotate(t_set **s, t_set **n);
void					set_right_rotate(t_set **s, t_set **n);

/*
** =============================================================================
** Solution Functions
** =============================================================================
*/

void					find_pivot(t_list *lst, int n, int *sp, int *bp);
void					b_to_a(t_ps **ps, int n);
void					a_to_b(t_ps **ps, int n);

/*
** =============================================================================
** Test Functions
** =============================================================================
*/

void					iterate(t_ps **ps, int cnt, void (*f)(t_ps **));
void					test_push(t_ps **ps);
void					test_rotate(t_ps **ps);
void					test_rrotate(t_ps **ps);
void					test_swap(t_ps **ps);

#endif
