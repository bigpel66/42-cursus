/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:08:15 by jseo              #+#    #+#             */
/*   Updated: 2021/03/09 23:24:15 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct
{
	int fd;
	long long i;

	char flag;
	int width;
	long long precision;
	char length;
	int type;

	int size;
} t_form;

int is_digit(int c);
int is_flag(int c);
int is_length(int c);
int is_type(int c);

t_form *form_create(t_form *f);
void form_init(t_form *f);
void form_read(t_form *f, const char *format, va_list ap);
void form_write(t_form *f, const char *format, va_list ap);

void *ft_memset(void *s, int c, size_t n);
int ft_printf(const char *format, ...);
char *ft_strchr(const char *s, int c);
size_t ft_strlen(const char *s);

int parse_check(const char *format, va_list ap);
int parse_string(t_form *f, const char *format, va_list ap);

void get_flag(t_form *f, const char *format, va_list ap);
int get_index(const char *s, char c);
void get_length(t_form *f, const char *format);
int get_width(t_form *f, const char *format);
long long get_precision(t_form *f, const char *format);

void process_asterisk(t_form *f, va_list ap);
void process_dot(t_form *f, const char *format, va_list ap);

#endif
