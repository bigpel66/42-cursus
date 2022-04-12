# Copy into the Configuration Directory
cp /wp-config.php /var/www/wordpress/wp-config.php

# WordPress Core Download
wp core download --allow-root --path=/var/www/wordpress

# WordPress Core Installation with Configuration Value
wp core install --allow-root --path=/var/www/wordpress --url="$WP_URL" --title="$WP_TITLE" --admin_user="$WP_ADMIN_USER" --admin_password="$WP_ADMIN_PWD" --admin_email="$WP_ADMIN_EMAIL" --skip-email

# User Creation for WordPress Author
wp user create --allow-root --path=/var/www/wordpress $WP_USER $WP_USER_EMAIL --role=author --user-pass=$WP_USER_PWD

# Delete Script
rm /wp-config.php

# Run Daemon (It is OK to run Daemon because of Dumb Init)
php-fpm7 -F
