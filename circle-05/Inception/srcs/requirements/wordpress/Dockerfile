# Base Image (Latest Stable Version 3.14)
FROM    alpine:3.14

# Package Installation
RUN     apk update && \
        apk add curl mariadb-client redis php7 php7-phar php7-json php7-curl php7-fpm php7-mysqli php7-iconv && \
        wget -O /usr/bin/dumb-init https://github.com/Yelp/dumb-init/releases/download/v1.2.5/dumb-init_1.2.5_x86_64 && \
        chmod +x /usr/bin/dumb-init && \
        mkdir -p /var/www/wordpress /usr/local/bin/wp /run/php && \
        curl https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar --output /usr/bin/wp --silent && \
        chmod +x /usr/bin/wp

# Copy Files
COPY    conf/www.conf /etc/php7/php-fpm.d/www.conf
COPY    conf/wp-config.php /wp-config.php
COPY    tools/script.sh /script.sh

# Permission Control
RUN     chmod +x /script.sh

# Expose Port
EXPOSE  9000

# Handle Every Signal Correctly by Dumb Init to PID 1
ENTRYPOINT [ "/usr/bin/dumb-init", "--"]

# Command to Execute by Entrypoint
CMD [ "sh", "-c", "/script.sh"]
