# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/03 16:08:00 by jseo              #+#    #+#              #
#    Updated: 2021/03/09 14:59:35 by jseo             ###   ########.fr        #
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

SRC_LIST	=	ft_printf.c		\
			ft_parse_format.c	\
			ft_create_info.c	\
			ft_process_string.c	\
			ft_process_info.c	\
			ft_process_flag.c	\
			ft_process_width.c	\
			ft_process_precision.c	\
			ft_process_length.c	\
			ft_process_print.c	\
			ft_init_info.c		\
			ft_memset.c		\
			ft_strchr.c		\
			ft_strlen.c		\
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
