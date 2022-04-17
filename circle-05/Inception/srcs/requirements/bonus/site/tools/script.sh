# !/bin/sh

# Check Whether Configuration File Exists or Not
if [ ! -f "/etc/nginx/conf.d/default.conf" ]; then
  # Copy Configuration File
  cp /tmp/default.conf /etc/nginx/conf.d/default.conf
  # Make WordPress Ready to Run Nginx
  sleep 5;
fi

# Run by Dumb Init (It is ok, if target is executed by daemon)
nginx -g 'daemon off;'
