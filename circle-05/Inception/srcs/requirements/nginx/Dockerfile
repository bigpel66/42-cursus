# Base Image (Latest Stable Version 3.14)
FROM    alpine:3.14

# Package Installation
RUN     apk update && \
        apk add nginx openssl && \
        wget -O /usr/bin/dumb-init https://github.com/Yelp/dumb-init/releases/download/v1.2.5/dumb-init_1.2.5_x86_64 && \
        chmod +x /usr/bin/dumb-init && \
        mkdir -p /run/nginx /var/www/wordpress /etc/nginx/tls && \
        openssl req -new -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
          -out /etc/nginx/tls/jseo.42.fr.crt \
          -keyout /etc/nginx/tls/jseo.42.fr.key \
          -subj "/C=KR/L=Seoul/O=42/OU=42Seoul/CN=jseo.42.fr"

# Copy Files
COPY    conf/nginx.conf /etc/nginx/http.d/default.conf

# Symbolic Link Stdout and Stderr to Log Files
RUN     ln -sf /dev/stdout /var/log/nginx/access.log && \
        ln -sf /dev/stderr /var/log/nginx/error.log

# Handle Every Signal Correctly by Dumb Init to PID 1
ENTRYPOINT [ "/usr/bin/dumb-init", "--"]

# Command to Execute by Entrypoint
CMD ["nginx", "-g", "daemon off;"]
