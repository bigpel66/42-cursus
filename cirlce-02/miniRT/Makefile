CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -g
RM				=	rm -f
NORM			=	norminette

NAME			=	miniRT
DYLD			=	./mlx/
LIB				=	libmlx.dylib
HEADER			=	./includes/
FOLDER			=	./srcs/

SRC_LIST		=	chk_ambient.c				\
					chk_camera.c				\
					chk_cylinder.c				\
					chk_light.c					\
					chk_plane.c					\
					chk_resolution.c			\
					chk_sphere.c				\
					chk_square.c				\
					chk_triangle.c				\
					color.c						\
					debug.c						\
					e_argument.c				\
					e_element_dup.c				\
					e_element_identifier.c		\
					e_element_memory.c			\
					e_element_parse.c			\
					e_file_extname.c			\
					e_file_open.c				\
					e_file_read.c				\
					e_mlx_run.c					\
					e_screen_connection.c		\
					e_window.c					\
					ft_string_alloc.c			\
					ft_string_gnl.c				\
					ft_string_util.c			\
					get_ambient.c				\
					get_camera.c				\
					get_cylinder.c				\
					get_identifier.c			\
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
					is_newline.c				\
					main.c						\
					memory.c					\
					mlx_ready.c					\
					rand.c						\
					scene.c						\
					series_double.c				\
					series_int.c				\
					unit_double.c				\
					unit_int.c					\
					valid_color.c				\
					valid_vec3.c				\
					vec_calc.c					\
					vec_feat.c					\
					vec_info.c					\
					vec_rand.c

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
