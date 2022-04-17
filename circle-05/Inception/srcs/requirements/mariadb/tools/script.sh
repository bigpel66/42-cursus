# !/bin/sh

# Check Whether Already Set Up or Not by Custom File
cat .setup 2> /dev/null

# If Not Set Up Yet
if [ $? -ne 0 ]; then
  # Execute MariaDB Daemon as a Background Process to Set Up
  /usr/bin/mysqld_safe --datadir=/var/lib/mysql &
  # Change Config to Use Not Only Socket But Also Network
  sed -i "s/skip-networking/# skip-networking/g" /etc/my.cnf.d/mariadb-server.cnf
  # Change Config to Allow Every Host
  sed -i "s/.*bind-address\s*=.*/bind-address=0.0.0.0\nport=3306/g" /etc/my.cnf.d/mariadb-server.cnf
  # Check Server Status Whether Configuration File Applied Well or Not
  if ! mysqladmin --wait=30 ping; then
    printf "MariaDB Daemon Unreachable\n"
    exit 1
  fi
  # Read Query with Deleting New Lines and Embracing Quotes and Eval with Env Variables
  eval "echo \"$(cat /tmp/query.sql)\"" | mariadb
  # Terminate MariaDB Daemon
  pkill mariadb
  # Mark as Set Up Finished
  touch .setup
fi

# Run by Dumb Init
/usr/bin/mysqld_safe --datadir=/var/lib/mysql
