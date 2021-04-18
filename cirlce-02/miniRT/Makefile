CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f
NORM			=	~/.norminette/norminette.rb

NAME			=	miniRT
DYLD			=	./mlx/
LIB				=	libmlx.dylib
HEADER			=	./includes/
FOLDER			=	./srcs/

SRC_LIST		=	dalloc.c					\
					debug.c						\
					e_argument.c				\
					e_file_descriptor.c			\
					e_file_extname.c			\
					e_file_parsing.c			\
					e_memory.c					\
					e_screen_connection.c		\
					e_window.c					\
					free_ptr.c					\
					ft_memset.c					\
					ft_strappend.c				\
					ft_strchr.c					\
					ft_strdup.c					\
					ft_strlcpy.c				\
					ft_strlen.c					\
					ft_strncmp.c				\
					get_next_line.c				\
					is_blank.c					\
					is_newline.c				\
					main.c

SRCS			=	$(addprefix $(FOLDER), $(SRC_LIST))
OBJS			=	$(SRCS:.c=.o)

%.o				:	%.c
					$(CC) $(CFLAGS) -I $(HEADER) -I $(DYLD) -o $@ -c $<

$(NAME)			:	$(OBJS)
					@make -C $(DYLD)
					$(CC) $(CFLAGS) -I $(HEADER) -I $(DYLD) -o $(NAME) $(OBJS) -L $(DYLD) -l mlx -framework OpenGL -framework AppKit
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

.PHONY			:	norm
norm			:
					$(NORM) $(HEADER)*.[ch]
					$(NORM) $(FOLDER)*.[ch]
