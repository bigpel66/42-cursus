NAME		=	inception

.PHONY	: all
all			: $(NAME)

$(NAME)	:
					sed -i "" 's/INSTALL=0/INSTALL=1/g' srcs/.env
					mkdir -p ~/jseo/data/wordpress ~/jseo/data/mariaDB
					docker-compose -f srcs/docker-compose.yml up --force-recreate --build -d

.PHONY	: clean
clean		:
					sed -i "" 's/INSTALL=1/INSTALL=0/g' srcs/.env
					docker-compose -f srcs/docker-compose.yml down

.PHONY	: fclean
fclean	:	clean
					rm -rf ~/jseo/data/wordpress/* ~/jseo/data/mariaDB/*
					docker volume rm srcs_volume-mariadb srcs_volume-wordpress

.PHONY	: re
re			: fclean  all

.PHONY	: log
log			:
					docker-compose -f srcs/docker-compose.yml logs


.PHONY	: ps
ps			:
					docker-compose -f srcs/docker-compose.yml ps

