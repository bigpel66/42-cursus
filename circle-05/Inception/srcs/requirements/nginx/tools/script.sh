# !/bin/sh

# Check Whether Configuration File Exists or Not
if [ ! -f "/etc/nginx/conf.d/default.conf" ]; then
  # Copy Configuration File
  cp /tmp/nginx.conf /etc/nginx/conf.d/default.conf
  # Make WordPress Ready to Run Nginx
  sleep 5;
fi

# Run by Dumb Init
nginx -g 'daemon off;'
