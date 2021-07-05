# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/28 13:17:56 by jseo              #+#    #+#              #
#    Updated: 2021/07/05 15:24:46 by jseo             ###   ########.fr        #
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
S_FOLDER			=		./srcs/
B_FOLDER			=		./srcs/bonus/

SRC_LIST			=		main.c
BNS_LIST			=

SRC					=		$(addprefix $(S_FOLDER), $(SRC_LIST))
BNS					=		$(addprefix $(B_FOLDER), $(BNS_LIST))

S_OBJ				=		$(SRC:.c=.o)
B_OBJ				=		$(BNS:.c=.o)

%.o					:		%.c
							@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)
							@$(CC) $(CLFAGS) $(CDEBUG) -I $(HEADER) -o $@ -c $<

$(NAME)				:		$(S_OBJ)
							@echo $(GREEN) "Source files are compiled!\n" $(EOC)
							@echo $(WHITE) "Building pipex for" $(YELLOW) "Mandatory" $(WHITE) "..." $(EOC)
							@$(CC) $(CFLAGS) $(CDEBUG) -I $(HEADER) -o $(NAME) $(S_OBJ)
							@echo $(GREEN) "pipex is created!\n" $(EOC)

.PHONY				:		all
all					:		$(NAME)

.PHONY				:		clean
clean				:
							@echo $(YELLOW) "Cleaning object files..." $(EOC)
							@$(RM) $(S_OBJ) $(B_OBJ)
							@echo $(RED) "Object files are cleaned!\n" $(EOC)

.PHONY				:		fclean
fclean				:		clean
							@echo $(YELLOW) "Removing pipex..." $(EOC)
							@$(RM) $(NAME)
							@echo $(RED) "pipex is removed!\n" $(EOC)

.PHONY				:		re
re					:		fclean all

.PHONY				:		bonus
bonus				:		$(S_OBJ) $(B_OBJ)
							@echo $(GREEN) "Source files are compiled!\n" $(EOC)
							@echo $(WHITE) "Building pipex for" $(YELLOW) "Bonus" $(WHITE) "..." $(EOC)
							@$(CC) $(CFLAGS) $(CDEBUG) -I $(HEADER) -o $(NAME) $(S_OBJ) $(B_OBJ)
							@echo $(GREEN) "pipex is created!\n" $(EOC)
