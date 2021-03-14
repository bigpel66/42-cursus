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
LIBFT		=	libft
LIBFT_ARC	=	libft.a

HEADER		=	includes
FOLDER		=	srcs

SRC_LIST	=	form_create.c		\
				form_init.c			\
				form_read.c			\
				form_write.c		\
				free_ptr.c			\
				ft_calloc.c			\
				ft_memset.c			\
				ft_printf.c			\
				ft_strchr.c			\
				ft_strlen.c			\
				get_flag.c			\
				get_index.c			\
				get_length.c		\
				get_precision.c		\
				get_width.c			\
				is_digit.c			\
				is_error.c			\
				is_flag.c			\
				is_length.c			\
				is_type.c			\
				parse_check.c		\
				parse_string.c		\
				print_type_c.c		\
				print_type_p.c		\
				print_type_s.c		\
				print_type_tag.c	\
				process_asterisk.c	\
				process_bonus.c		\
				process_decimal.c	\
				process_dot.c		\
				main.c
SRCS		=	$(addprefix $(FOLDER)/, $(SRC_LIST))
OBJS		=	$(SRCS:.c=.o)

%.o	:	%.c
		$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

$(NAME)	:	$(OBJS)
		make all -C $(LIBFT)
		cp $(LIBFT)/$(LIBFT_ARC) ./$(NAME)
		$(AR) $(NAME) $(OBJS)

.PHONY	:	all
all	:	$(NAME)

.PHONY	:	clean
clean	:
		$(RM) $(OBJS)
		make clean -C $(LIBFT)

.PHONY	:	fclean
fclean	:	clean
		$(RM) $(NAME)
		make fclean -C $(LIBFT)

.PHONY	:	re
re	:	fclean all


t	:
		$(CC) -I $(HEADER) -o test $(SRCS)

.PHONY	:	t
t	:	t


.PHONY	:	r
r	:
		$(RM) test

.PHONY	:	l
l	:	r t
