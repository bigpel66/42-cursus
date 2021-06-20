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

BLACK				= 		"\033[0;30m"
GRAY				= 		"\033[1;30m"
RED					=		"\033[0;31m"
GREEN				=		"\033[0;32m"
YELLOW				=		"\033[1;33m"
PURPLE				=		"\033[0;35m"
CYAN				=		"\033[0;36m"
WHITE				=		"\033[1;37m"
EOC					=		"\033[0;0m"
LINE_CLEAR			=		"\x1b[1A\x1b[M"

CC					=		gcc
CFLAGS				=		-Wall -Werror -Wextra
RM					=		rm -f
CHECKER				=		checker
PUSH_SWAP			=		push_swap
NAME				=		$(CHECKER) $(PUSH_SWAP)

HEADER_DIR			=		./includes/
CHECKER_DIR			=		./srcs/checker/
PUSH_SWAP_DIR		=		./srcs/push_swap/
SHARED_DIR			=		./srcs/shared/
TEST_DIR			=		./test/

D_VAL				=		validation/
D_SOL				=		solution/
D_CTX				=		context/
D_INST				=		instruction/
D_JFUNC				=		j_function/
D_SET				=		rb_set/

CHECKER_SRC_LIST	=		$(D_VAL)panel.c					\
							$(D_VAL)yield.c					\
							$(D_VAL)simulate.c				\
							checker.c
PUSH_SWAP_SRC_LIST	=		$(D_SOL)pred.c					\
							$(D_SOL)node.c					\
							$(D_SOL)stack.c					\
							$(D_SOL)yield.c					\
							push_swap.c
SHARED_SRC_LIST		=		$(D_CTX)initiation.c			\
							$(D_CTX)termination.c			\
							$(D_INST)iterate.c				\
							$(D_INST)push.c					\
							$(D_INST)rotate.c				\
							$(D_INST)rrotate.c				\
							$(D_INST)swap.c					\
							$(D_JFUNC)jatoi.c				\
							$(D_JFUNC)jcalloc.c				\
							$(D_JFUNC)jfree.c				\
							$(D_JFUNC)jgnl.c				\
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
							$(D_JFUNC)jstrappend.c			\
							$(D_JFUNC)jstrdup.c				\
							$(D_JFUNC)jstrlcpy.c			\
							$(D_JFUNC)jstrlen.c				\
							$(D_JFUNC)jstrncmp.c			\
							$(D_JFUNC)jstrtrim.c			\
							$(D_SET)alloc.c					\
							$(D_SET)color.c					\
							$(D_SET)delete.c				\
							$(D_SET)inorder.c				\
							$(D_SET)insert.c				\
							$(D_SET)rotate.c

CHECKER_SRCS		=		$(addprefix $(CHECKER_DIR), $(CHECKER_SRC_LIST))
CHECKER_OBJS		=		$(CHECKER_SRCS:.c=.o)

PUSH_SWAP_SRCS		=		$(addprefix $(PUSH_SWAP_DIR), $(PUSH_SWAP_SRC_LIST))
PUSH_SWAP_OBJS		=		$(PUSH_SWAP_SRCS:.c=.o)

SHARED_SRCS			=		$(addprefix $(SHARED_DIR), $(SHARED_SRC_LIST))
SHARED_OBJS			=		$(SHARED_SRCS:.c=.o)

OBJS				=		$(CHECKER_OBJS) $(PUSH_SWAP_OBJS) $(SHARED_OBJS)

%.o					:		%.c
							@echo $(YELLOW) "Compiling...\t" $@ $(EOC) $(LINE_CLEAR)
							@$(CC) $(CFLAGS) -I $(HEADER_DIR) -o $@ -c $<

$(NAME)				:		$(OBJS)
							@echo $(GREEN) "Object File Compiled!\n" $(EOC)
							@echo $(YELLOW) "checker Building..." $(EOC)
							@$(CC) $(CFLAGS) -I $(HEADER_DIR) -o $(CHECKER) $(CHECKER_OBJS) $(SHARED_OBJS)
							@echo $(YELLOW) "push_swap Building..." $(EOC)
							@$(CC) $(CFLAGS) -I $(HEADER_DIR) -o $(PUSH_SWAP) $(PUSH_SWAP_OBJS) $(SHARED_OBJS)
							@echo $(GREEN) "Ready to be Executed!\n\n" $(EOC)

.PHONY				:		all
all					:		$(NAME)

.PHONY				:		clean
clean				:
							@echo $(YELLOW) "Object File Cleaning..." $(EOC)
							@$(RM) $(SHARED_OBJS) $(CHECKER_OBJS) $(PUSH_SWAP_OBJS)
							@echo $(RED) "Object File Cleaned!\n" $(EOC)

.PHONY				:		fclean
fclean				:		clean
							@echo $(YELLOW) "checker Removing..." $(EOC)
							@$(RM) $(CHECKER)
							@echo $(RED) "checker Removed!\n" $(EOC)
							@echo $(YELLOW) "push_swap Removing..." $(EOC)
							@$(RM) $(PUSH_SWAP)
							@echo $(RED) "push_swap Removed!\n\n" $(EOC)

.PHONY				:		re
re					:		fclean all

.PHONY				:		bonus
bonus				:		all

.PHONY				:		norm
norm				:
							norminette *

.PHONY				:		checker_error
checker_error		:
							@echo $(CYAN) "checker Error Testing...\n" $(EOC)
							@chmod 777 $(TEST_DIR)checker_error.sh
							@bash $(TEST_DIR)checker_error.sh
							@echo $(EOC)

.PHONY				:		checker_false
checker_false		:
							@echo $(CYAN) "checker False Testing...\n" $(EOC)
							@chmod 777 $(TEST_DIR)checker_false.sh
							@bash $(TEST_DIR)checker_false.sh
							@echo $(EOC)

.PHONY				:		checker_true
checker_true		:
							@echo $(CYAN) "checker True Testing...\n" $(EOC)
							@chmod 777 $(TEST_DIR)checker_true.sh
							@bash $(TEST_DIR)checker_true.sh
							@echo $(EOC)

.PHONY				:		checker_test
checker_test		:		all checker_error checker_false checker_true

.PHONY				:		push_swap_identity
push_swap_identity	:
							@echo $(CYAN) "push_swap Identity Testing...\n" $(EOC)
							@chmod 777 $(TEST_DIR)push_swap_identity.sh
							@bash $(TEST_DIR)push_swap_identity.sh
							@echo $(EOC)

.PHONY				:		push_swap_vsimple
push_swap_vsimple	:
							@echo $(CYAN) "push_swap Simple Version Testing...\n" $(EOC)
							@chmod 777 $(TEST_DIR)push_swap_vsimple.sh
							@bash $(TEST_DIR)push_swap_vsimple.sh
							@echo $(EOC)

.PHONY				:		push_swap_vmiddle
push_swap_vmiddle	:
							@echo $(CYAN) "push_swap Middle Version Testing...\n" $(EOC)
							@chmod 777 $(TEST_DIR)push_swap_vmiddle.sh
							@bash $(TEST_DIR)push_swap_vmiddle.sh
							@echo $(EOC)

.PHONY				:		push_swap_vadvanced
push_swap_vadvanced	:
							@echo $(CYAN) "push_swap Advanced Version Testing...\n" $(EOC)
							@chmod 777 $(TEST_DIR)push_swap_vadvanced.sh
							@bash $(TEST_DIR)push_swap_vadvanced.sh
							@echo $(EOC)

.PHONY				:		push_swap_test
push_swap_test		:		all push_swap_identity push_swap_vsimple push_swap_vmiddle push_swap_vadvanced

.PHONY				:		test
test				:		checker_test push_swap_test
