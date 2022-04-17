# !/bin/sh

# Check Whether Change on Configuration File is Needed or Not
grep -E "listen = 127.0.0.1" /etc/php7/php-fpm.d/www.conf > /dev/null 2>&1

# If Configuration File Needs to be Changed
if [ $? -eq 0 ]; then
  # Change the Listening Host with 8000 Port
  sed -i "s/.*listen = 127.0.0.1.*/listen = 8000/g" /etc/php7/php-fpm.d/www.conf
fi

# Check Whether index.php File Exists or Not
if [ ! -f "/var/www/wordpress/adminer/index.php" ]; then
  # Create Directory on WordPress to Serve Adminer
  mkdir -p /var/www/wordpress/adminer
  # Download a Sole Adminer Page
  curl -s -L https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1-mysql-en.php --output /var/www/wordpress/adminer/index.php
fi

# Run by Dumb Init
php-fpm7 --nodaemonize
