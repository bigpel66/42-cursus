-- Delete Already Existing Root User
DELETE FROM
  mysql.user
WHERE
  User = '$MARIADB_ADMIN_USER'
  AND Host NOT IN (
    '$MARIADB_HOST_NAME',
    '$MARIADB_HOST_V4',
    '$MARIADB_HOST_V6'
  );

-- Set Password of Root User on Daemon
SET
  PASSWORD FOR '$MARIADB_ADMIN_USER' @'$MARIADB_HOST_NAME' = PASSWORD('$MARIADB_ADMIN_PWD');

-- Create WordPress Database
CREATE DATABASE IF NOT EXIST '$MARIADB_DB';

-- Create Another User for WordPress
CREATE USER '$MARIADB_USER' @'%' IDENTIFIED BY '$MARIADB_PWD';

-- Grant Permissions
GRANT ALL PRIVILEGES ON '$MARIADB_DB.*' TO '$MARIADB_USER' @'%' WITH GRANT OPTION;

-- Apply
FLUSH PRIVILEGES;
