CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -g
RM				=	rm -f
NORM			=	norminette

NAME			=	miniRT
DYLD			=	./mlx/
LIB				=	libmlx.dylib
HEADER			=	./includes/
FOLDER			=	./srcs/

SRC_LIST		=	error/element.c				\
					error/file.c				\
					error/mlx.c					\
					ft_str/alloc.c				\
					ft_str/gnl.c				\
					ft_str/util.c				\
					get_element/ambient.c		\
					get_element/camera.c		\
					get_element/cylinder.c		\
					get_element/light.c			\
					get_element/plane.c			\
					get_element/resolution.c	\
					get_element/sphere.c		\
					get_element/square.c		\
					get_element/triangle.c		\
					parse/get_identifier.c		\
					parse/get_index.c			\
					parse/get_val_double.c		\
					parse/get_val_int.c			\
					parse/scene.c				\
					ray_tracer/math.c			\
					ray_tracer/update.c			\
					vector/calc.c				\
					vector/feat.c				\
					vector/info.c				\
					vector/rand.c				\
					color.c						\
					main.c						\
					memory.c					\
					mlx_ready.c					\
					ostream.c					\
					valid.c

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
