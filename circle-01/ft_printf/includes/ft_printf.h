/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:23:19 by jseo              #+#    #+#             */
/*   Updated: 2021/03/18 12:31:03 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>

# define TR 				1
# define FL 				0
# define ERR 				-1
# define IGNR 				-2

typedef int					t_bool;
typedef unsigned char		t_char;

typedef struct
{
	int				fd;
	ssize_t			size;

	long long		i;
	long long		dig;

	t_char			flg;
	long long		width;
	long long		prec;
	t_char			length;
	int				t;

	long long		p_len;
	long long		s_len;
	t_char			p_val;
	t_char			s_val;
}					t_form;

void				console_out(t_form *f, t_char c, long long len);
t_bool				dalloc(void **ptr, size_t cnt, size_t n);

void				form_init(t_form *f);
void				form_read(t_form *f, const char *format, va_list ap);
void				form_write(t_form *f, va_list ap);

void				free_ptr(void **ptr);

void				*ft_memset(void *s, int c, size_t n);
int					ft_printf(const char *format, ...);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *s);
t_bool				ft_wcheck_mb_cur_max(wchar_t *s);
ssize_t				ft_wputchar_fd(wchar_t c, int fd);
ssize_t				ft_wputstr_fd(wchar_t *s, int fd);
size_t				ft_wstrlen(wchar_t *s);
t_bool				ft_wtob(char *s, wchar_t c);

t_bool				get_dec_signed(t_form *f, intmax_t v, void **ptr);
t_bool				get_dec_unsigned(t_form *f, uintmax_t v, void **ptr);
void				get_flag(t_form *f, const char *format, va_list ap);
t_bool				get_hex(t_form *f, uintmax_t v, t_bool cap, void **ptr);
int					get_index(const char *s, char c);
void				get_length(t_form *f, const char *format);
t_bool				get_oct(t_form *f, uintmax_t v, void **ptr);
long long			get_precision(t_form *f, const char *format);
int					get_width(t_form *f, const char *format);

t_bool				is_digit(int c);
t_bool				is_error(t_form *f);
t_bool				is_flag(int c);
t_bool				is_length(int c);
t_bool				is_type(int c);

void				padd_non_str(t_form *f, int padd);
void				padd_str(t_form *f, t_bool str);
void				padd_swap(t_form *f);
void				padd_with_dot(t_form *f, int padd);
void				padd_without_dot(t_form *f, int padd);

ssize_t				parse_check(const char *format, va_list ap);
ssize_t				parse_format(t_form *f, const char *format, va_list ap);

t_bool				prnt_dec_signed(t_form *f, intmax_t v, t_bool sig);
t_bool				prnt_dec_unsigned(t_form *f, uintmax_t v, t_bool sig);
t_bool				prnt_hex(t_form *f, uintmax_t v, t_bool cap, t_bool adr);
t_bool				prnt_oct(t_form *f, uintmax_t v);
t_bool				prnt_str(t_form *f, char *s, t_bool str);
t_bool				prnt_wstr(t_form *f, wchar_t *s, t_bool str);

void				process_asterisk(t_form *f, va_list ap);
t_bool				process_bonus(t_form *f, va_list ap);
void				process_dot(t_form *f, const char *format, va_list ap);
t_bool				process_length_nbr(t_form *f, va_list ap);
t_bool				process_length_str(t_form *f, va_list ap);
t_bool				process_length_nothing(t_form *f, va_list ap);
t_bool				process_nbr_h(t_form *f, va_list ap);
t_bool				process_nbr_hh(t_form *f, va_list ap);
t_bool				process_nbr_l(t_form *f, va_list ap);
t_bool				process_nbr_ll(t_form *f, va_list ap);
t_bool				process_nbr(t_form *f, va_list ap);
t_bool				process_nothing_h(t_form *f, void *ptr);
t_bool				process_nothing_hh(t_form *f, void *ptr);
t_bool				process_nothing_l(t_form *f, void *ptr);
t_bool				process_nothing_ll(t_form *f, void *ptr);
t_bool				process_nothing(t_form *f, void *ptr);
t_bool				process_str_l(t_form *f, va_list ap);
t_bool				process_str(t_form *f, va_list ap);

#endif
