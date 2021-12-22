# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 16:57:22 by jseo              #+#    #+#              #
#    Updated: 2021/12/22 18:40:02 by jseo             ###   ########.fr        #
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
D_RB		=	redblack/
SRC_LIST	=	$(D_RB)utils.c			\
				main.c
SRC			=	$(addprefix $(FOLDER), $(SRC_LIST))
OBJ			=	$(SRC:.c=.o)

# =============================================================================
# Target Generating
# =============================================================================

%.o			:	%.c
				@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)
				@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $< -I $(LIB_HEADER)

$(NAME)		:	$(OBJ)
				@echo $(GREEN) "Source files are compiled!\n" $(EOC)
				@echo $(WHITE) "Building $(NAME) for" $(YELLOW) "Mandatory" $(WHITE) "..." $(EOC)
				@$(CC) $(CFALGS) -I $(HEADER) -o $(NAME) $(OBJ) -I $(LIB_HEADER) -l $(LIB_NAME) -L $(LIB_FOLDER)
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
				@echo $(YELLOW) "Removing $(NAME)..." $(EOC)
				@$(RM) $(NAME)
				@echo $(RED) "$(NAME) is removed!\n\n" $(EOC)

.PHONY		:	re
re			:	fclean all

.PHONY		:	norm
norm		:
				@norminette
