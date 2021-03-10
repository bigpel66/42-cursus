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
	int i;

	char flag;
	int width;
	int precision;
	int length;
	int type;

	int size;
} t_form;

int check_digit(int c);
int check_flag(int c);
int check_length(const char *c);
int check_type(int c);

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

void process_flag(t_form *f, const char *format, va_list ap);
void process_length(t_form *f, const char *format);
void process_type(t_form *f, const char *format);
void process_width(t_form *f, const char *format);

#endif
