# !/bin/sh

# Check Whether Change on Configuration File is Needed or Not
grep -E "listen = 127.0.0.1" /etc/php7/php-fpm.d/www.conf > /dev/null 2>&1

# If Configuration File Needs to be Changed
if [ $? -eq 0 ]; then
  # Change the Listening Host with 9000 Port
  sed -i "s/.*listen = 127.0.0.1.*/listen = 9000/g" /etc/php7/php-fpm.d/www.conf
  # Append Env Variables on the Configuration File
  echo "env[MARIADB_HOST] = \$MARIADB_HOST" >> /etc/php7/php-fpm.d/www.conf
  echo "env[MARIADB_USER] = \$MARIADB_USER" >> /etc/php7/php-fpm.d/www.conf
  echo "env[MARIADB_PWD] = \$MARIADB_PWD" >> /etc/php7/php-fpm.d/www.conf
  echo "env[MARIADB_DB] = \$MARIADB_DB" >> /etc/php7/php-fpm.d/www.conf
fi

# Check Whether Another Configuration File Exists or Not
if [ ! -f "/var/www/wordpress/wp-config.php" ]; then
  # Copy Configuration File
  cp /tmp/wp-config.php /var/www/wordpress/wp-config.php
  # Wait MariaDB to be Prepared (MariaDB Container is Running Daemon by the Script, not Daemon Directly)
  sleep 5;
  # Check Whether Database Server is Alive or Not
  if ! mysqladmin -h $MARIADB_HOST -u $MARIADB_USER --password=$MARIADB_PWD --wait=60 ping > /dev/null; then
    printf "MariaDB Daemon Unreachable\n"
    exit 1
  fi
  # WordPress Stuffs
  wp core install --url="$WP_URL" --title="$WP_TITLE" --admin_user="$WP_ADMIN_USER" --admin_password="$WP_ADMIN_PWD" --admin_email="$WP_ADMIN_EMAIL" --skip-email --path=/var/www/wordpress
  wp plugin install redis-cache --activate --path=/var/www/wordpress
  wp plugin update --all --path=/var/www/wordpress
  wp user create $WP_USER $WP_USER_EMAIL --role=author --user_pass=$WP_USER_PWD --path=/var/www/wordpress
  wp redis enable --path=/var/www/wordpress
fi

# Run by Dumb Init
php-fpm7 --nodaemonize
