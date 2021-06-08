# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/02 18:26:08 by jseo              #+#    #+#              #
#    Updated: 2021/06/03 19:22:34 by jseo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#							Declare Variables
################################################################################
ws_usr="www-data"
ws_grp="www-data"
dir_collection="/Downloads"
dir_certificate="/cert"
dir_wordpress="/var/www/html/wordpress"
dir_phpmyadmin="/var/www/html/phpmyadmin"
tar_wordpress="latest.tar.gz"
tar_phpmyadmin="phpMyAdmin-latest-all-languages.tar.gz"
url_wordpress="https://wordpress.org/latest.tar.gz"
url_phpmyadmin="https://www.phpmyadmin.net/downloads/\
phpMyAdmin-latest-all-languages.tar.gz"
log_stdout="/var/log/server_stdout"
log_stderr="/var/log/server_stderr"

################################################################################
#							Create Directories
################################################################################
echo		-e "\033[0;33mCreating Directories for Server Setting..."
mkdir		$dir_collection
mkdir		$dir_certificate
mkdir		$dir_wordpress
mkdir		$dir_phpmyadmin
echo		-e "\033[0;32mFinished!\033[0m\n"

################################################################################
#							Create SSL Certificate
################################################################################
echo		-e "\033[0;33mCreating SSL Certificate for HTTPS..."
openssl		genrsa															\
			-out $dir_certificate/private.key								\
			2048															\
			>> $log_stdout 2> $log_stderr
openssl		rsa -in $dir_certificate/private.key							\
			-pubout -out $dir_certificate/public.key						\
			>> $log_stdout 2> $log_stderr
openssl		req -new 														\
			-subj "/CN=$sv_hst"												\
			-key $dir_certificate/private.key								\
			-out $dir_certificate/server.csr								\
			>> $log_stdout 2> $log_stderr
openssl		genrsa															\
			-out $dir_certificate/cert.key									\
			2048															\
			>> $log_stdout 2> $log_stderr
openssl		req -new -x509													\
			-subj "/CN=$sv_hst"												\
			-key $dir_certificate/cert.key									\
			-out $dir_certificate/cert.pem									\
			>> $log_stdout 2> $log_stderr
openssl		x509 -req -in $dir_certificate/server.csr						\
			-CA $dir_certificate/cert.pem									\
			-CAkey $dir_certificate/cert.key								\
			-CAcreateserial													\
			-out $dir_certificate/server.crt								\
			>> $log_stdout 2> $log_stderr
chmod		600 $dir_certificate/*
echo		-e "\033[0;32mFinished!\033[0m\n"

################################################################################
#							Create Scripts
################################################################################
echo		-e "\033[0;33mCreating Scripts for Server Setting..."
bash		/tmp/default_generator.sh										\
			$dir_certificate/server.crt										\
			$dir_certificate/private.key									\
			$sv_hst															\
			>> /default
bash		/tmp/query_generator.sh											\
			$sv_hst															\
			$db_doc															\
			$db_usr															\
			$db_pas															\
			>> /query.sql
bash		/tmp/status_generator.sh										\
			>> /status.sql
echo		-e "\033[0;32mFinished!\033[0m\n"

################################################################################
#							Substitue Nginx Conf
################################################################################
echo		-e "\033[0;33mSubstituting Nginx Configuration File..."
rm			-rf /etc/nginx/sites-available/default
mv			/default														\
			/etc/nginx/sites-available/default
if			[	"$autoindex"	=	true	]				; then
			sed		"s/autoindex off/autoindex on/"							\
					-i /etc/nginx/sites-available/default
fi
if			[	"$autoindex"	=	false	]				; then
			sed		"s/autoindex on/autoindex off/"							\
					-i /etc/nginx/sites-available/default
fi
echo		-e "\033[0;32mFinished!\033[0m\n"

################################################################################
#							Service Start
################################################################################
echo		-e "\033[0;33mService Starting...\033[0m"
service		mysql							start
service		nginx							start
service		php7.3-fpm						start
echo		-e "\033[0;32mFinished!\033[0m\n"

################################################################################
#							Install WordPress
################################################################################
echo		-e "\033[0;33mInstalling WordPress..."
wget		-P $dir_collection												\
			$url_wordpress													\
			>> $log_stdout 2> $log_stderr
tar			-xvf $dir_collection/$tar_wordpress								\
			--strip-components=1											\
			-C $dir_wordpress												\
			>> $log_stdout 2> $log_stderr
chown		-R $ws_usr:$ws_grp												\
			$dir_wordpress
cp			-p																\
			$dir_wordpress/wp-config-sample.php								\
			$dir_wordpress/wp-config.php
sed			"s/database_name_here/$db_doc/;									\
			s/username_here/$db_usr/;										\
			s/password_here/$db_pas/"										\
			-i $dir_wordpress/wp-config.php
echo		-e "\033[0;32mFinished!\033[0m\n"

################################################################################
#							Install phpMyAdmin
################################################################################
echo		-e "\033[0;33mInstalling phpMyAdmin..."
wget		-P $dir_collection												\
			$url_phpmyadmin													\
			>> $log_stdout 2> $log_stderr
tar			-xvf $dir_collection/$tar_phpmyadmin							\
			--strip-components=1											\
			-C $dir_phpmyadmin												\
			>> $log_stdout 2> $log_stderr
chown		-R $ws_usr:$ws_grp												\
			$dir_phpmyadmin
cp			-p																\
			$dir_phpmyadmin/config.sample.inc.php							\
			$dir_phpmyadmin/config.inc.php
sed			"s/secret'\] = ''/secret'\] = '$db_sec'/"						\
			-i $dir_phpmyadmin/config.inc.php
echo		-e "\033[0;32mFinished!\033[0m\n"

################################################################################
#							Config MySQL
################################################################################
echo		-e "\033[0;33mConfigurating MySQL for Services...\033[0m"
mysql		-u$db_usr														\
			-p$db_pas														\
			< /query.sql													\
			>> $log_stdout 2> $log_stderr
mysql		-u$db_usr														\
			-p$db_pas														\
			< $dir_phpmyadmin/sql/create_tables.sql							\
			>> $log_stdout 2> $log_stderr
mysql		-u$db_usr														\
			-p$db_pas														\
			< /status.sql														\
			>> /databases.txt
sed			"1d"															\
			-i /databases.txt
while		read	line 								; do				\
			echo	-e "[\033[0;32m DB \033[0m] $line"	; done				\
			< /databases.txt
echo		-e "\033[0;32mFinished!\033[0m\n"

################################################################################
#							Service Restart
################################################################################
echo		-e "\033[0;33mService Starting Again...\033[0m"
service		nginx							reload
service		php7.3-fpm						restart
echo		-e "\033[0;32mFinished!\033[0m\n"

################################################################################
#							Delete Useless Files & Directories
################################################################################
echo		-e "\033[0;33mDeleting Files & Directories for Setting Server..."
rm			-rf $dir_collection
rm			-rf /query.sql
rm			-rf /status.sql
rm			-rf /databases.txt
rm			-rf	/tmp/default_generator.sh
rm			-rf /tmp/query_generator.sh
rm			-rf	/tmp/status_generator.sh
rm			-rf /tmp/run.sh
echo		-e "\033[0;32mFinished!\033[0m\n"

################################################################################
#							Unset ENV Variables
################################################################################
unset		sv_hst
unset		db_doc
unset		db_usr
unset		db_pas
unset		db_sec

################################################################################
#							Keep PID 1
################################################################################
bash
