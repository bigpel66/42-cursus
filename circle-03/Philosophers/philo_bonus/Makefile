# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 16:57:22 by jseo              #+#    #+#              #
#    Updated: 2021/07/13 17:49:23 by jseo             ###   ########.fr        #
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

NAME				=		philo_bonus
HEADER				=		./includes/
FOLDER				=		./srcs/

SRC_LIST			=		philo_bonus.c
SRC					=		$(addprefix $(FOLDER), $(SRC_LIST))
OBJ					=		$(SRC:.c=.o)

%.o					:		%.c
							@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)
							@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

$(NAME)				:		$(OBJ)
							@echo $(GREEN) "Source files are compiled!\n" $(EOC)
							@echo $(WHITE) "Building $(NAME) for" $(YELLOW) "Mandatory" $(WHITE) "..." $(EOC)
							@$(CC) $(CFALGS) -I $(HEADER) -o $(NAME) $(OBJ)
							@echo $(GREEN) "$(NAME) is created!\n" $(EOC)

.PHONY				:		all
all					:		$(NAME)

.PHONY				:		clean
clean				:
							@echo $(YELLOW) "Cleaning object files..." $(EOC)
							@$(RM) $(OBJ)
							@echo $(RED) "Object files are cleaned!\n" $(EOC)

.PHONY				:		fclean
fclean				:		clean
							@echo $(YELLOW) "Removing $(NAME)..." $(EOC)
							@$(RM) $(NAME)
							@echo $(RED) "$(NAME) is removed!\n" $(EOC)

.PHONY				:		re
re					:		fclean all

.PHONY				:		norm
norm				:
							@norminette
