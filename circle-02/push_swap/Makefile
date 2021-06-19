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

BLACK							= 			"\003[1;30m"
RED								=			"\033[1;31m"
GREEN							=			"\033[1;32m"
YELLOW							=			"\033[1;33m"
CYAN							=			"\033[1;35m"
PURPLE							=			"\033[1;36m"
WHITE							=			"\033[1;37m"
EOC								=			"\033[0;0m"
LINE_CLEAR						=			"\x1b[1A\x1b[M"

CC								=			gcc
CFLAGS							=			-Wall -Werror -Wextra -g -fsanitize=address
RM								=			rm -f
CHECKER							=			checker
PUSH_SWAP						=			push_swap
NAME							=			$(CHECKER) $(PUSH_SWAP)

HEADER_DIR						=			./includes/
CHECKER_DIR						=			./srcs/checker/
PUSH_SWAP_DIR					=			./srcs/push_swap/
SHARED_DIR						=			./srcs/shared/

D_SOL							=			solution/
D_CTX							=			context/
D_INST							=			instruction/
D_JFUNC							=			j_function/
D_SET							=			rb_set/

CHECKER_SRC_LIST				=			checker.c
PUSH_SWAP_SRC_LIST				=			$(D_SOL)pred.c					\
											$(D_SOL)node.c					\
											$(D_SOL)stack.c					\
											$(D_SOL)yield.c					\
											push_swap.c
SHARED_SRC_LIST					=			$(D_CTX)initiation.c			\
											$(D_CTX)termination.c			\
											$(D_INST)iterate.c				\
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
											$(D_SET)rotate.c

CHECKER_SRCS					=			$(addprefix $(CHECKER_DIR), $(CHECKER_SRC_LIST))
CHECKER_OBJS					=			$(CHECKER_SRCS:.c=.o)

PUSH_SWAP_SRCS					=			$(addprefix $(PUSH_SWAP_DIR), $(PUSH_SWAP_SRC_LIST))
PUSH_SWAP_OBJS					=			$(PUSH_SWAP_SRCS:.c=.o)

SHARED_SRCS						=			$(addprefix $(SHARED_DIR), $(SHARED_SRC_LIST))
SHARED_OBJS						=			$(SHARED_SRCS:.c=.o)

OBJS							=			$(CHECKER_OBJS) $(PUSH_SWAP_OBJS) $(SHARED_OBJS)

%.o								:			%.c
											@echo $(YELLOW) "Compiling...\t" $@ $(EOC) $(LINE_CLEAR)
											@$(CC) $(CFLAGS) -I $(HEADER_DIR) -o $@ -c $<

$(NAME)							:			$(OBJS)
											@echo $(GREEN) "Object File Compiled!\n" $(EOC)
											@echo $(YELLOW) "checker Building..." $(EOC)
											@$(CC) $(CFLAGS) -I $(HEADER_DIR) -o $(CHECKER) $(CHECKER_OBJS) $(SHARED_OBJS)
											@echo $(YELLOW) "push_swap Building..." $(EOC)
											@$(CC) $(CFLAGS) -I $(HEADER_DIR) -o $(PUSH_SWAP) $(PUSH_SWAP_OBJS) $(SHARED_OBJS)
											@echo $(GREEN) "Ready to be Executed!\n" $(EOC)

.PHONY							:			all
all								:			$(NAME)

.PHONY							:			clean
clean							:
											@echo $(YELLOW) "Object File Cleaning..." $(EOC)
											@$(RM) $(SHARED_OBJS) $(CHECKER_OBJS) $(PUSH_SWAP_OBJS)
											@echo $(RED) "Object File Cleaned!\n" $(EOC)

.PHONY							:			fclean
fclean							:			clean
											@echo $(YELLOW) "checker Removing..." $(EOC)
											@$(RM) $(CHECKER)
											@echo $(RED) "checker Removed!\n" $(EOC)
											@echo $(YELLOW) "push_swap Removing..." $(EOC)
											@$(RM) $(PUSH_SWAP)
											@echo $(RED) "push_swap Removed!\n" $(EOC)

.PHONY							:			re
re								:			fclean all

.PHONY							:			bonus
bonus							:			all

.PHONY							:			norm
norm							:
											norminette *
