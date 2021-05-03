CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f

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
					$(D_OBJ)hit.c				\
					$(D_OBJ)plane.c				\
					$(D_OBJ)sphere.c			\
					$(D_OBJ)square.c			\
					$(D_OBJ)status.c			\
					$(D_OBJ)triangle.c			\
					$(D_PAR)double.c			\
					$(D_PAR)identifier.c		\
					$(D_PAR)index.c				\
					$(D_PAR)int.c				\
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
					ray.c						\
					scatter.c					\
					valid.c

SRCS			=	$(addprefix $(FOLDER), $(SRC_LIST))
OBJS			=	$(SRCS:.c=.o)

%.o				:	%.c
					@echo "\n\033[0;32mObject File Compiliing..."
					$(CC) $(CFLAGS) -I $(HEADER) -I $(DYLD) -o $@ -c $<
					@echo "\033[0m"

$(NAME)			:	$(OBJS)
					@echo "\n\033[0;32mminiRT Building..."
					$(CC) $(CFLAGS) -I $(HEADER) -I $(DYLD) -o $(NAME) $(OBJS) -L $(DYLD) -l mlx -framework OpenGL -framework AppKit
					@install_name_tool -change $(LIB) $(DYLD)$(LIB) $(NAME)
					@echo "\033[0m"

.PHONY			:	all
all				:	$(NAME)

.PHONY			:	clean
clean			:
					@echo "\033[0;31mObject File Cleaning..."
					$(RM) $(OBJS)
					@echo "\033[0m"

.PHONY			:	fclean
fclean			:	clean
					@echo "\033[0;31mminiRT Removing..."
					$(RM) *.bmp
					$(RM) $(NAME)
					@echo "\033[0m"

.PHONY			:	re
re				:	fclean all

.PHONY			:	bonus
bonus			:	all
