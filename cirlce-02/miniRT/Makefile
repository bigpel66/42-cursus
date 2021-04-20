CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -g
RM				=	rm -f
NORM			=	norminette

NAME			=	miniRT
DYLD			=	./mlx/
LIB				=	libmlx.dylib
HEADER			=	./includes/
FOLDER			=	./srcs/

SRC_LIST		=	dalloc.c					\
					debug.c						\
					e_argument.c				\
					e_file_extname.c			\
					e_file_open.c				\
					e_file_parsing.c			\
					e_file_read.c				\
					e_memory.c					\
					e_screen_connection.c		\
					e_window.c					\
					free_ptr.c					\
					ft_gnl.c					\
					ft_memset.c					\
					ft_strappend.c				\
					ft_strchr.c					\
					ft_strdup.c					\
					ft_strlcpy.c				\
					ft_strlen.c					\
					ft_strncmp.c				\
					get_ambient.c				\
					get_camera.c				\
					get_cylinder.c				\
					get_index.c					\
					get_light.c					\
					get_plane.c					\
					get_resolution.c			\
					get_sphere.c				\
					get_square.c				\
					get_triangle.c				\
					is_blank.c					\
					is_digit.c					\
					is_endl.c					\
					is_identifier.c				\
					is_newline.c				\
					main.c						\
					mlx_ready.c					\
					sdouble.c					\
					sint.c						\
					valid_color.c				\
					valid_vec3.c				\
					vdouble.c					\
					vint.c

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
					$(NORM) $(HEADER)*.[ch] $(FOLDER)*.[ch]
