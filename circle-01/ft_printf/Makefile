# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/03 16:08:00 by jseo              #+#    #+#              #
#    Updated: 2021/03/09 22:52:13 by jseo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RM		=	rm -f
AR		=	ar rc

NAME		=	libftprintf.a

HEADER		=	includes
FOLDER		=	srcs

SRC_LIST	=	allocate_null_str.c		\
				allocate_with_dot.c		\
				allocate_without_dot.c	\
				form_create.c			\
				form_init.c				\
				form_read.c				\
				form_write.c			\
				free_multi_ptr.c		\
				free_unit_ptr.c			\
				ft_calloc.c				\
				ft_memset.c				\
				ft_printf.c				\
				ft_strchr.c				\
				ft_strlen.c				\
				get_dec.c				\
				get_flag.c				\
				get_hex.c				\
				get_index.c				\
				get_length.c			\
				get_precision.c			\
				get_width.c				\
				is_digit.c				\
				is_error.c				\
				is_flag.c				\
				is_length.c				\
				is_type.c				\
				padd_non_str.c			\
				padd_str.c				\
				parse_check.c			\
				parse_format.c			\
				print_dec.c				\
				print_hex.c				\
				print_str.c				\
				process_asterisk.c		\
				process_bonus.c			\
				process_dot.c			\
				process_nbr.c			\
				process_str.c
SRCS		=	$(addprefix $(FOLDER)/, $(SRC_LIST))
OBJS		=	$(SRCS:.c=.o)

%.o	:	%.c
		$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

$(NAME)	:	$(OBJS)
		$(AR) $(NAME) $(OBJS)

.PHONY	:	all
all	:	$(NAME)

.PHONY	:	clean
clean	:
		$(RM) $(OBJS)

.PHONY	:	fclean
fclean	:	clean
		$(RM) $(NAME)

.PHONY	:	re
re	:	fclean all


t	:
		$(CC) -I $(HEADER) -o test $(SRCS) ./main.c

.PHONY	:	t
t	:	t


.PHONY	:	r
r	:
		$(RM) test

.PHONY	:	l
l	:	r t
