# Base Image (Currently Most Stable Version 3.13)
FROM        alpine:3.13

# Package Installation
RUN         apk update && \
            apk add nginx openssl && \
            wget -O /usr/bin/dumb-init https://github.com/Yelp/dumb-init/releases/download/v1.2.5/dumb-init_1.2.5_x86_64 && \
            chmod +x /usr/bin/dumb-init && \
            mkdir -p /etc/nginx/tls /var/run/nginx && \
            openssl req -new -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/nginx/tls/jseo.42.fr.crt -keyout /etc/nginx/tls/jseo.42.fr.key -subj "/C=KR/ST=Seoul/L=Songpa-gu/O=42/OU=42Seoul/CN=jseo.42.fr" && \
            ln -sf /dev/stdout /var/log/nginx/access.log && \
            ln -sf /dev/stderr /var/log/nginx/error.log && \
            rm -rf /etc/nginx/conf.d/default.conf

# Copy Files
COPY        conf/nginx.conf /tmp/nginx.conf
COPY        tools/script.sh /tmp/script.sh

# Permission Control
RUN         chmod +x /tmp/script.sh

# Explicitly Specify to Expose the Port to the Public though Using Bridge
EXPOSE      443

# Handle Every Signal Correctly by Dumb Init to PID 1
ENTRYPOINT  [ "/usr/bin/dumb-init", "--" ]

# Command to Execute by Entrypoint
CMD         [ "sh", "-c", "/tmp/script.sh" ]
