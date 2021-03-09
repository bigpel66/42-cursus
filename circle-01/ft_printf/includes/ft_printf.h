/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:08:15 by jseo              #+#    #+#             */
/*   Updated: 2021/03/09 14:59:34 by jseo             ###   ########.fr       */
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
	int size;

	int minus;
	int zero;
	int dot;
	int star;
	int plus;
	int space;
	int hash;

	int width;
	int precision;
	int length;

	int bytes;
}		t_info;

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	*ft_memset(void *s, int c, size_t n);
void	ft_init_info(t_info *i);
void	ft_process_print(t_info *i, const char *format, va_list ap);
void	ft_process_length(t_info *i, const char *format);
void	ft_process_precision(t_info *i, const char *format);
void	ft_process_width(t_info *i, const char *format);
void	ft_process_flag(t_info *i, const char *format);
void	ft_process_info(t_info *i, const char *format);
int		ft_process_string(t_info *i, const char *format, va_list ap);
t_info	*ft_create_info(t_info *i);
int		ft_parse_format(const char *format, va_list ap);
int		ft_printf(const char *format, ...);

#endif
