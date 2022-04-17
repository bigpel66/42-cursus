# !/bin/sh

# Check Whether Change on Configuration File is Needed or Not
grep -E "bind 127.0.0.1" /etc/redis.conf > /dev/null 2>&1

# If Configuration File Needs to be Changed
if [ $? -eq 0 ]; then
  # Change the Binding Host to Allow Every IP Address
  sed -i "s/bind 127.0.0.1/bind 0.0.0.0/g" /etc/redis.conf
fi

# Check Whether Change on Configuration File is Needed or Not
grep -E "protected-mode yes" /etc/redis.conf > /dev/null 2>&1

# If Configuration File Needs to be Changed
if [ $? -eq 0 ]; then
  # Change the Binding Host to Allow Every IP Address
  sed -i "s/protected-mode yes/protected-mode no/g" /etc/redis.conf
fi

# Run by Dumb Init
redis-server /etc/redis.conf
