/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:01:32 by jseo              #+#    #+#             */
/*   Updated: 2021/06/10 15:33:35 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
** =============================================================================
** Dependencies
** =============================================================================
*/

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

/*
** =============================================================================
** Macro Constants
** =============================================================================
*/

# define VALID			0
# define INVALID		1

# define SA				0
# define SB				1
# define SS				2
# define PA				3
# define PB				4
# define RA				5
# define RB				6
# define RR				7
# define RRA			8
# define RRB			9
# define RRR			10

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
}						t_ps;

/*
** =============================================================================
** Context Functions
** =============================================================================
*/

bool					args_check(int argc, char **argv, t_ps **ps);
bool					args_unique(t_ps **ps);
bool					args_sorted(t_ps **ps);
void					exit_invalid(t_ps **ps);
void					exit_valid(t_ps **ps);

/*
** =============================================================================
** Instruction Functions
** =============================================================================
*/

void					inst_pa(t_ps **ps);
void					inst_pb(t_ps **ps);
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
t_list					*jlstlast(t_list *lst);
bool					jlstnew(t_list **lst, int v);
size_t					jlstsize(t_list *lst);
void					jmemset(void *s, int c, size_t n);
void					jputchar(char c, int fd);
void					jputnbr(int n, int fd);
void					jputstr(char *s, int fd);
size_t					jstrlen(const char *s);
int						jstrncmp(const char *s1, const char *s2, size_t n);
void					jstrtrim(char **s);

/*
** =============================================================================
** Set Functions
** =============================================================================
*/

void					set_alloc_root(t_set **r, t_set **n);
void					set_alloc_rest(t_set **r, t_set **n);
void					set_red_color(t_set **r, t_set **n, t_set *u);
void					set_llb_color(t_set **r, t_set **n);
void					set_lrb_color(t_set **r, t_set **n);
void					set_rlb_color(t_set **r, t_set **n);
void					set_rrb_color(t_set **r, t_set **n);
void					set_delete(t_set **r);
void					set_inorder(t_set **r);
bool					set_insert(t_set **r, int v);
void					set_left_rotate(t_set **r, t_set **n);
void					set_right_rotate(t_set **r, t_set **n);

/*
** =============================================================================
** Map Functions
** =============================================================================
*/

void					map_alloc_root(t_map **r, t_map **n);
void					map_alloc_rest(t_map **r, t_map **n);
void					map_red_color(t_map **r, t_map **n, t_map *u);
void					map_llb_color(t_map **r, t_map **n);
void					map_lrb_color(t_map **r, t_map **n);
void					map_rlb_color(t_map **r, t_map **n);
void					map_rrb_color(t_map **r, t_map **n);
void					map_delete(t_map **r);
void					map_inorder(t_map **r);
bool					map_insert(t_map **r, char *k, char *v);
void					map_left_rotate(t_map **r, t_map **n);
void					map_right_rotate(t_map **r, t_map **n);

#endif
