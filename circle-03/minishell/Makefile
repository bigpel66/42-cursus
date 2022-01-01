# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 16:57:22 by jseo              #+#    #+#              #
#    Updated: 2022/01/01 17:30:26 by jseo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================================================================
# Color Variables
# =============================================================================

BLACK		= 	"\033[0;30m"
GRAY		= 	"\033[1;30m"
RED			=	"\033[0;31m"
GREEN		=	"\033[0;32m"
YELLOW		=	"\033[1;33m"
PURPLE		=	"\033[0;35m"
CYAN		=	"\033[0;36m"
WHITE		=	"\033[1;37m"
EOC			=	"\033[0;0m"
LINE_CLEAR	=	"\x1b[1A\x1b[M"

# =============================================================================
# Command Variables
# =============================================================================

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
CDEBUG		=	-fsanitize=address -g
RM			=	rm -f

# =============================================================================
# Library Variables
# =============================================================================

LIB_NAME	=	readline
LIB_HEADER	=	./readline/8.1.1/include/
LIB_FOLDER	=	./readline/8.1.1/lib/

# =============================================================================
# File Variables
# =============================================================================

NAME		=	minishell
HEADER		=	./includes/
FOLDER		=	./srcs/
D_AS		=	astree/
D_BUILT		=	builtin/
D_EXEC		=	exec/
D_JFUNC		=	jfunction/
D_PARSE		=	parse/
D_RB		=	rbtree/
D_RUN		=	runtime/
SRC_LIST	=	main.c						\
				$(D_AS)check.c				\
				$(D_AS)exec.c				\
				$(D_AS)frag_1.c				\
				$(D_AS)frag_2.c				\
				$(D_BUILT)cd.c				\
				$(D_BUILT)echo.c			\
				$(D_BUILT)env.c				\
				$(D_BUILT)exit.c			\
				$(D_BUILT)export.c			\
				$(D_BUILT)pwd.c				\
				$(D_BUILT)unset.c			\
				$(D_EXEC)command_1.c		\
				$(D_EXEC)command_2.c		\
				$(D_EXEC)command_3.c		\
				$(D_EXEC)command_4.c		\
				$(D_EXEC)pipe.c				\
				$(D_EXEC)rdr_1.c			\
				$(D_EXEC)rdr_2.c			\
				$(D_JFUNC)jabs.c			\
				$(D_JFUNC)jatoi.c			\
				$(D_JFUNC)jcalloc.c			\
				$(D_JFUNC)jfree.c			\
				$(D_JFUNC)jgnl.c			\
				$(D_JFUNC)jisalnum.c		\
				$(D_JFUNC)jisalpha.c		\
				$(D_JFUNC)jisascii.c		\
				$(D_JFUNC)jisdigit.c		\
				$(D_JFUNC)jisprint.c		\
				$(D_JFUNC)jisspace.c		\
				$(D_JFUNC)jitoa.c			\
				$(D_JFUNC)jlstadd_back.c	\
				$(D_JFUNC)jlstadd_front.c	\
				$(D_JFUNC)jlstclear.c		\
				$(D_JFUNC)jlstdelone.c		\
				$(D_JFUNC)jlstiter.c		\
				$(D_JFUNC)jlstlast.c		\
				$(D_JFUNC)jlstmap.c			\
				$(D_JFUNC)jlstnew.c			\
				$(D_JFUNC)jlstshow.c		\
				$(D_JFUNC)jlstsize.c		\
				$(D_JFUNC)jmemset.c			\
				$(D_JFUNC)jnumlen.c			\
				$(D_JFUNC)jputchar.c		\
				$(D_JFUNC)jputendl.c		\
				$(D_JFUNC)jputnbr.c			\
				$(D_JFUNC)jputstr.c			\
				$(D_JFUNC)jsplit.c			\
				$(D_JFUNC)jstrappend.c		\
				$(D_JFUNC)jstrchr.c			\
				$(D_JFUNC)jstrdup.c			\
				$(D_JFUNC)jstrjoin.c		\
				$(D_JFUNC)jstrlcpy.c		\
				$(D_JFUNC)jstrlen.c			\
				$(D_JFUNC)jstrncmp.c		\
				$(D_JFUNC)jstrtrim.c		\
				$(D_JFUNC)jsubstr.c			\
				$(D_JFUNC)jtolower.c		\
				$(D_JFUNC)jtoupper.c		\
				$(D_JFUNC)jwordlen.c		\
				$(D_PARSE)expand_1.c		\
				$(D_PARSE)expand_2.c		\
				$(D_PARSE)pair.c			\
				$(D_PARSE)tokenize.c		\
				$(D_RB)check.c				\
				$(D_RB)delete_1.c			\
				$(D_RB)delete_2.c			\
				$(D_RB)insert_1.c			\
				$(D_RB)insert_2.c			\
				$(D_RB)print.c				\
				$(D_RB)search.c				\
				$(D_RB)util_1.c				\
				$(D_RB)util_2.c				\
				$(D_RB)util_3.c				\
				$(D_RUN)assert.c			\
				$(D_RUN)loop.c				\
				$(D_RUN)signal.c
SRC			=	$(addprefix $(FOLDER), $(SRC_LIST))
OBJ			=	$(SRC:.c=.o)

# =============================================================================
# Target Generating
# =============================================================================

%.o			:	%.c
				@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)
				@$(CC) $(CFLAGS) $(CDEBUG) -I $(HEADER) -o $@ -c $< -I $(LIB_HEADER)

$(NAME)		:	$(OBJ)
				@echo $(GREEN) "Source files are compiled!\n" $(EOC)
				@echo $(WHITE) "Building $(NAME) for" $(YELLOW) "Mandatory" $(WHITE) "..." $(EOC)
				@$(CC) $(CFALGS) $(CDEBUG) -I $(HEADER) -o $(NAME) $(OBJ) -I $(LIB_HEADER) -l $(LIB_NAME) -L $(LIB_FOLDER)
				@echo $(GREEN) "$(NAME) is created!\n" $(EOC)

# =============================================================================
# Rules
# =============================================================================

.PHONY		:	all
all			:	$(NAME)

.PHONY		:	clean
clean		:
				@echo $(YELLOW) "Cleaning object files..." $(EOC)
				@$(RM) $(OBJ)
				@echo $(RED) "Object files are cleaned!\n" $(EOC)

.PHONY		:	fclean
fclean		:	clean
				@$(RM) .heredoc
				@echo $(YELLOW) "Removing $(NAME)..." $(EOC)
				@$(RM) $(NAME)
				@echo $(RED) "$(NAME) is removed!\n\n" $(EOC)

.PHONY		:	re
re			:	fclean all

.PHONY		:	norm
norm		:
				@norminette
