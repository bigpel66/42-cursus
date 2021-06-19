# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 22:35:11 by jseo              #+#    #+#              #
#    Updated: 2021/06/15 13:38:20 by jseo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=			gcc
CFLAGS		=			-Wall -Werror -Wextra -g -fsanitize=address
RM			=			rm -f
NAME		=			push_swap

HEADER		=			./includes/
FOLDER		=			./srcs/

D_CTX		=			context/
D_INST		=			instruction/
D_JFUNC		=			j_function/
D_SET		=			rb_set/
D_SOL		=			solution/
D_TEST		=			test/

SRC_LIST	=			$(D_CTX)initiation.c			\
						$(D_CTX)panel.c					\
						$(D_CTX)termination.c			\
						$(D_INST)push.c					\
						$(D_INST)rotate.c				\
						$(D_INST)rrotate.c				\
						$(D_INST)swap.c					\
						$(D_JFUNC)jatoi.c				\
						$(D_JFUNC)jcalloc.c				\
						$(D_JFUNC)jfree.c				\
						$(D_JFUNC)jisdigit.c			\
						$(D_JFUNC)jisspace.c			\
						$(D_JFUNC)jlstclear.c			\
						$(D_JFUNC)jlstempty.c			\
						$(D_JFUNC)jlstlast.c			\
						$(D_JFUNC)jlstnew.c				\
						$(D_JFUNC)jlstshow.c			\
						$(D_JFUNC)jlstsize.c			\
						$(D_JFUNC)jmemset.c				\
						$(D_JFUNC)jnumlen.c				\
						$(D_JFUNC)jputchar.c			\
						$(D_JFUNC)jputnbr.c				\
						$(D_JFUNC)jputstr.c				\
						$(D_JFUNC)jstrlen.c				\
						$(D_JFUNC)jstrncmp.c			\
						$(D_JFUNC)jstrtrim.c			\
						$(D_SET)alloc.c					\
						$(D_SET)color.c					\
						$(D_SET)delete.c				\
						$(D_SET)inorder.c				\
						$(D_SET)insert.c				\
						$(D_SET)rotate.c				\
						$(D_SOL)pred.c					\
						$(D_SOL)node.c					\
						$(D_SOL)stack.c					\
						$(D_SOL)yield.c					\
						$(D_TEST)iterate.c				\
						$(D_TEST)push.c					\
						$(D_TEST)rotate.c				\
						$(D_TEST)rrotate.c				\
						$(D_TEST)swap.c					\
						main.c

SRCS		=			$(addprefix $(FOLDER), $(SRC_LIST))
OBJS		=			$(SRCS:.c=.o)

%.o			:			%.c
						@echo "\n\033[0;32mObject File Compiling..."
						$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<
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
