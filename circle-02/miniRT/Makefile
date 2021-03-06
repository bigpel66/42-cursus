# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 10:33:37 by jseo              #+#    #+#              #
#    Updated: 2021/06/10 18:14:14 by jseo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f

NAME			=	miniRT
DYLD			=	./mlx/
LIB				=	libmlx.dylib
HEADER			=	./includes/
FOLDER			=	./srcs/

D_BMP			=	bmp/
D_EXT			=	exit/
D_FT			=	ft/
D_GET			=	get_element/
D_INIT			=	init/
D_MLX			=	mlx/
D_OBJ			=	object/
D_PAN			=	panel/
D_PAR			=	parse/
D_RAY			=	ray/
D_VEC			=	vector/

SRC_LIST		=	$(D_BMP)read.c				\
					$(D_BMP)write.c				\
					$(D_EXT)element.c			\
					$(D_EXT)file.c				\
					$(D_EXT)mlx.c				\
					$(D_EXT)pthread.c			\
					$(D_EXT)texture.c			\
					$(D_FT)alloc.c				\
					$(D_FT)gnl.c				\
					$(D_FT)memory.c				\
					$(D_FT)util.c				\
					$(D_GET)ambient.c			\
					$(D_GET)camera.c			\
					$(D_GET)cone.c				\
					$(D_GET)cylinder.c			\
					$(D_GET)light.c				\
					$(D_GET)plane.c				\
					$(D_GET)resolution.c		\
					$(D_GET)sphere.c			\
					$(D_GET)square.c			\
					$(D_GET)triangle.c			\
					$(D_INIT)camera.c			\
					$(D_INIT)color.c			\
					$(D_INIT)image.c			\
					$(D_INIT)object.c			\
					$(D_INIT)pthread.c			\
					$(D_INIT)ray.c				\
					$(D_INIT)scene.c			\
					$(D_INIT)texture.c			\
					$(D_INIT)vector.c			\
					$(D_MLX)alpha_omega.c		\
					$(D_MLX)calc.c				\
					$(D_MLX)control.c			\
					$(D_MLX)handle.c			\
					$(D_MLX)run.c				\
					$(D_MLX)save.c				\
					$(D_OBJ)cone.c				\
					$(D_OBJ)cylinder.c			\
					$(D_OBJ)hit.c				\
					$(D_OBJ)plane.c				\
					$(D_OBJ)sphere.c			\
					$(D_OBJ)square.c			\
					$(D_OBJ)triangle.c			\
					$(D_PAN)error_list.c		\
					$(D_PAN)status.c			\
					$(D_PAN)template.c			\
					$(D_PAN)to_string1.c		\
					$(D_PAN)to_string2.c		\
					$(D_PAR)double.c			\
					$(D_PAR)int.c				\
					$(D_PAR)part.c				\
					$(D_PAR)scene.c				\
					$(D_PAR)valid.c				\
					$(D_RAY)color.c				\
					$(D_RAY)scatter.c			\
					$(D_RAY)trace.c				\
					$(D_VEC)calc1.c				\
					$(D_VEC)calc2.c				\
					$(D_VEC)calc3.c				\
					$(D_VEC)math.c				\
					$(D_VEC)rand.c				\
					guide.c						\
					main.c

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

.PHONY			:	norm
norm			:
					norminette *
