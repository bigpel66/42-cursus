/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:01:32 by jseo              #+#    #+#             */
/*   Updated: 2021/06/10 14:14:19 by jseo             ###   ########.fr       */
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

typedef struct			s_mo
{
	t_list				*a;
	t_list				*b;
	t_list				*i;
	t_list				*t;
	int					cnt;
}						t_mo;

/*
** =============================================================================
** Library Functions
** =============================================================================
*/

void					jmemset(void *s, int c, size_t n);
size_t					jstrlen(const char *s);
void					jputstr(char *s, int fd);
bool					jcalloc(void **ptr, size_t cnt, size_t n);
void					jfree(void **ptr);
bool					jlstnew(t_list **lst, int v);
void					jlstdelone(t_list **lst);
void					jlstclear(t_list **lst);
t_list					*jlstlast(t_list *lst);
bool					jatoi(char **s, int *v);
void					jstrtrim(char **s);

/*
** =============================================================================
** Checking Functions
** =============================================================================
*/

bool					jisdigit(int c);
bool					jisspace(int c);

#endif
