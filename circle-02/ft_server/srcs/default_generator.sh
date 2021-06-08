# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    default_generator.sh                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/03 17:11:04 by jseo              #+#    #+#              #
#    Updated: 2021/06/03 19:17:59 by jseo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#							STDOUT for "default"
################################################################################
echo	"server {"
echo	"		listen 80;"
echo	"		listen [::]:80;"
echo	"		return 301 https://\$host\$request_uri;"
echo	"}"
echo	"server {"
echo	"		listen 443;"
echo	"		listen [::]:443;"
echo	"		ssl on;"
echo	"		ssl_certificate $1;"
echo	"		ssl_certificate_key $2;"
echo	"		root /var/www/html;"
echo	"		index index.html index.htm index.nginx-debian.html index.php;"
echo	"		server_name $3;"
echo	"		location / {"
echo	"					autoindex on;"
echo	"					try_files \$uri \$uri/ =404;"
echo	"		}"
echo	"		location ~ \\.php$ {"
echo	"					include snippets/fastcgi-php.conf;"
echo	"					fastcgi_pass unix:/run/php/php7.3-fpm.sock;"
echo	"		}"
echo	"}"
