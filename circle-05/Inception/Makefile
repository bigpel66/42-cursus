NAME	= inception

.PHONY	: all
all	: $(NAME)

$(NAME)	:
	sudo mkdir -p ${HOME}/data/wordpress ${HOME}/data/mariadb ${HOME}/data/site ${HOME}/data/monitor
ifeq ("$(wildcard .setup)", "")
	sudo chmod 777 /etc/hosts
	sudo echo "127.0.0.1 jseo.42.fr" >> /etc/hosts
	touch .setup
endif
	sudo docker-compose -f srcs/docker-compose.yml up --force-recreate --build -d

.PHONY	: clean
clean	:
	sudo docker-compose -f srcs/docker-compose.yml down -v --rmi all --remove-orphans

.PHONY	: fclean
fclean	: clean
	sudo rm -rf ${HOME}/data
	sudo rm -f .setup
	sudo docker system prune --volumes --all --force
	sudo docker network prune --force
	sudo docker volume prune --force

.PHONY	: re
re	: fclean all

.PHONY	: restart
restart	:
	sudo docker-compose -f srcs/docker-compose.yml restart

.PHONY	: log
log	:
	sudo docker-compose -f srcs/docker-compose.yml logs -f

.PHONY	: ps
ps	:
	sudo docker-compose -f srcs/docker-compose.yml ps
