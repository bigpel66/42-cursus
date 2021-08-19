/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:49:21 by jseo              #+#    #+#             */
/*   Updated: 2021/08/11 19:38:57 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

/*
** =============================================================================
** Dependencies
** =============================================================================
*/

# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

/*
** =============================================================================
** Macro Declaration
** =============================================================================
*/

# define EPSILON		10
# define MILLI			1000

/*
** =============================================================================
** Type Definitions
** =============================================================================
*/

typedef pthread_t		t_th;

/*
** =============================================================================
** Enum Type Definitions
** =============================================================================
*/

typedef enum e_exit
{
	VALID,
	INVALID,
}					t_exit;

typedef enum e_stat
{
	ERROR = -1,
	SUCCESS,
}					t_stat;

typedef enum e_cond
{
	DEAD,
	GRAB,
	EATING,
	SLEEPING,
	THINKING,
	FULL,
}					t_cond;

/*
** =============================================================================
** Struct Type Definitions
** =============================================================================
*/

typedef struct s_philo
{
	int				c;
	t_th			th;
	pid_t			pid;
	long long		cur;
}					t_philo;

typedef struct s_op
{
	int				i;
	int				total;
	int				time_die;
	int				time_eat;
	int				time_nap;
	int				limit;
	char			*f;
	char			*t;
	char			*p;
	char			*c;
	t_th			th;
	sem_t			*sem_f;
	sem_t			*sem_t;
	sem_t			*sem_p;
	sem_t			*sem_c;
	t_philo			*philo;
	long long		begin;
}					t_op;

/*
** =============================================================================
** Context Functions
** =============================================================================
*/

void	*achieve(void *arg);
void	*monitor(void *arg);
void	routine(t_op *op);
t_exit	exit_invalid(t_op *op, void (*f)(void));
t_exit	exit_valid(t_op *op);

/*
** =============================================================================
** Utility Functions
** =============================================================================
*/

bool	chrono(long long *val);
void	elapse(t_op *op, long long begin, long long limit);
bool	console(t_op *op, t_cond cond);
void	take_fork(t_op *op);
void	put_fork(t_op *op);
bool	semaphore(sem_t **sem, const char *file, size_t cnt);
void	philo_eat(t_op *op);
void	philo_sleep(t_op *op);
void	philo_think(t_op *op);

/*
** =============================================================================
** J Functions
** =============================================================================
*/

bool	jatoi(char **s, int *v);
bool	jcalloc(void **ptr, size_t cnt, size_t n);
void	jfree(void **ptr);
bool	jisdigit(int c);
bool	jisspace(int c);
void	*jmemset(void *s, int c, size_t n);
void	jputchar(char c, int fd);
void	jputendl(char *s, int fd);
void	jputnbr(int n, int fd);
void	jputstr(char *s, int fd);
size_t	jstrlen(const char *s);

#endif
