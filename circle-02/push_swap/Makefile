# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 22:35:11 by jseo              #+#    #+#              #
#    Updated: 2021/06/09 14:01:59 by jseo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=			gcc
CFLAGS		=			-Wall -Werror -Wextra -fsanitize=address
RM			=			rm -f
NAME		=			push_swap

HEADER		=			./
FOLDER		=			./

SRC_LIST	=			main.c			

SRCS		=			$(addprefix $(FOLDER), $(SRC_LIST))
OBJS		=			$(SRCS:.c=.o)

%.o			:			%.c
						@echo "\n\033[0;32mObject File Compiling..."
						$(CC) $(CLAGS) -I $(HEADER) -o $@ -c $<
						@echo "\033[0m"

$(NAME)		:			$(OBJS)
						@echo "\n\033[0;32mpush_swap Building..."
						$(CC) $(CFLAGS) -I $(HEADER) -o $(NAME) $(OBJS)
						@echo "\033[0m"

.PHONY		:			all
all			:			$(NAME)

.PHONY		:			clean
clean		:
						@echo "\n\033[0;31mObject File Cleaning..."
						$(RM) $(OBJS)
						@echo "\033[0m"

.PHONY		:			fclean
fclean		:			clean
						@echo "\n\033[0;31mpush_swap Removing..."
						$(RM) $(NAME)
						@echo "\033[m"

.PHONY		:			re
re			:			fclean all

.PHONY		:			bonus
bonus		:			all

.PHONY		:			norm
norm		:
						norminette *
