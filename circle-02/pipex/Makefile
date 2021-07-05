# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/28 13:17:56 by jseo              #+#    #+#              #
#    Updated: 2021/07/05 19:38:52 by jseo             ###   ########.fr        #
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
CDEBUG				=		-fsanitize=address -g
RM					=		rm -f
NAME				=		pipex

HEADER				=		./includes/
FOLDER				=		./srcs/

D_CTX				=		context/
D_JFUNC				=		j_function/

SHARED_SRC_LIST		=		$(D_CTX)execution.c			\
							$(D_CTX)initiation.c		\
							$(D_CTX)termination.c		\
							$(D_JFUNC)jcalloc.c			\
							$(D_JFUNC)jfree.c			\
							$(D_JFUNC)jmemset.c			\
							$(D_JFUNC)jsplit.c			\
							$(D_JFUNC)jstrlcpy.c		\
							$(D_JFUNC)jstrlen.c			\
							$(D_JFUNC)jstrncmp.c		\
							$(D_JFUNC)jsubstr.c
SRC_LIST			=		pipex.c
BNS_LIST			=		pipex_bonus.c

SHARED				=		$(addprefix $(FOLDER), $(SHARED_SRC_LIST))
SRC					=		$(addprefix $(FOLDER), $(SRC_LIST))
BNS					=		$(addprefix $(FOLDER), $(BNS_LIST))

SHARED_OBJ			=		$(SHARED:.c=.o)
SRC_OBJ				=		$(SRC:.c=.o)
BNS_OBJ				=		$(BNS:.c=.o)

%.o					:		%.c
							@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)
							@$(CC) $(CLFAGS) $(CDEBUG) -I $(HEADER) -o $@ -c $<

$(NAME)				:		$(SHARED_OBJ) $(SRC_OBJ)
							@echo $(GREEN) "Source files are compiled!\n" $(EOC)
							@echo $(WHITE) "Building pipex for" $(YELLOW) "Mandatory" $(WHITE) "..." $(EOC)
							@$(CC) $(CFLAGS) $(CDEBUG) -I $(HEADER) -o $(NAME) $(SHARED_OBJ) $(SRC_OBJ)
							@echo $(GREEN) "pipex is created!\n" $(EOC)

.PHONY				:		all
all					:		$(NAME)

.PHONY				:		clean
clean				:
							@echo $(YELLOW) "Cleaning object files..." $(EOC)
							@$(RM) $(SHARED_OBJ) $(SRC_OBJ) $(BNS_OBJ)
							@echo $(RED) "Object files are cleaned!\n" $(EOC)

.PHONY				:		fclean
fclean				:		clean
							@echo $(YELLOW) "Removing pipex..." $(EOC)
							@$(RM) $(NAME)
							@echo $(RED) "pipex is removed!\n" $(EOC)

.PHONY				:		re
re					:		fclean all

.PHONY				:		bonus
bonus				:		$(SHARED_OBJ) $(BNS_OBJ)
							@echo $(GREEN) "Source files are compiled!\n" $(EOC)
							@echo $(WHITE) "Building pipex for" $(YELLOW) "Bonus" $(WHITE) "..." $(EOC)
							@$(CC) $(CFLAGS) $(CDEBUG) -I $(HEADER) -o $(NAME) $(SHARED_OBJ) $(BNS_OBJ)
							@echo $(GREEN) "pipex is created!\n" $(EOC)
