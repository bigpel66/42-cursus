CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -g
RM				=	rm -f
NORM			=	norminette

NAME			=	miniRT
DYLD			=	./mlx/
LIB				=	libmlx.dylib
HEADER			=	./includes/
FOLDER			=	./srcs/

SRC_LIST		=	color.c						\
					debug.c						\
					e_element.c					\
					e_file.c					\
					e_mlx.c						\
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
					main.c						\
					math.c						\
					memory.c					\
					mlx_ready.c					\
					scene.c						\
					series_double.c				\
					series_int.c				\
					unit_double.c				\
					unit_int.c					\
					valid.c						\
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
