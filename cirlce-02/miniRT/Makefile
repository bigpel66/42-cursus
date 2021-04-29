CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -g
RM				=	rm -f
NORM			=	norminette

NAME			=	miniRT
DYLD			=	./mlx/
LIB				=	libmlx.dylib
HEADER			=	./includes/
FOLDER			=	./srcs/

D_ERR			=	error/
D_STR			=	ft_str/
D_GET			=	get_element/
D_MLX			=	mlx/
D_PAR			=	parse/
D_OBJ			=	object/
D_RT			=	ray_tracer/
D_SCN			=	scene/
D_VEC			=	vector/

SRC_LIST		=	$(D_ERR)element.c			\
					$(D_ERR)file.c				\
					$(D_ERR)memory.c			\
					$(D_ERR)mlx.c				\
					$(D_ERR)pthread.c			\
					$(D_STR)alloc.c				\
					$(D_STR)gnl.c				\
					$(D_STR)util.c				\
					$(D_GET)ambient.c			\
					$(D_GET)camera.c			\
					$(D_GET)cylinder.c			\
					$(D_GET)light.c				\
					$(D_GET)plane.c				\
					$(D_GET)resolution.c		\
					$(D_GET)sphere.c			\
					$(D_GET)square.c			\
					$(D_GET)triangle.c			\
					$(D_MLX)calc.c				\
					$(D_MLX)free.c				\
					$(D_MLX)run.c				\
					$(D_MLX)save.c				\
					$(D_MLX)setup.c				\
					$(D_OBJ)cylinder.c			\
					$(D_OBJ)plane.c				\
					$(D_OBJ)sphere.c			\
					$(D_OBJ)square.c			\
					$(D_OBJ)status.c			\
					$(D_OBJ)triangle.c			\
					$(D_PAR)double.c			\
					$(D_PAR)identifier.c		\
					$(D_PAR)index.c				\
					$(D_PAR)int.c				\
					$(D_RT)material.c			\
					$(D_RT)status.c				\
					$(D_SCN)open.c				\
					$(D_SCN)status.c			\
					$(D_VEC)calc.c				\
					$(D_VEC)feat.c				\
					$(D_VEC)info.c				\
					$(D_VEC)rand.c				\
					bmp.c						\
					camera.c					\
					color.c						\
					main.c						\
					math.c						\
					memory.c					\
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
					$(RM) $(OBJS)

.PHONY			:	fclean
fclean			:	clean
					@make -C $(DYLD) clean
					@$(RM) *.bmp
					$(RM) $(NAME)

.PHONY			:	re
re				:	fclean all

.PHONY			:	bonus
bonus			:	all

.PHONY			:	norm
norm			:
					$(NORM) $(HEADER)*.[ch] $(SRCS)
