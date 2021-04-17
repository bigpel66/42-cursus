CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f

NAME			=	miniRT
DYLD			=	./mlx/
LIB				=	libmlx.dylib
HEADER			=	./includes/
FOLDER			=	./srcs/

SRC_LIST		=	main.c

SRCS			=	$(addprefix $(FOLDER), $(SRC_LIST))
OBJS			=	$(SRCS:.c=.o)

%.o				:	%.c
					$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

$(NAME)			:	$(OBJS)
					@make -C $(DYLD)
					$(CC) $(CFLAGS) -I $(HEADER) -o $(NAME) $(OBJS) -L $(DYLD) -l mlx -framework OpenGL -framework AppKit
					@install_name_tool -change $(LIB) $(DYLD)$(LIB) $(NAME)

.PHONY			:	all
all				:	$(NAME)

.PHONY			:	clean
clean			:
					@make -C $(DYLD) clean
					$(RM) $(OBJS)

.PHONY			:	fclean
fclean			:	clean
					$(RM) $(NAME)

.PHONY			:	re
re				:	fclean all

.PHONY			:	bonus
bonus			:	all
