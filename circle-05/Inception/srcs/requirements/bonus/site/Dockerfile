# Base Image (Currently Most Stable Version 3.13)
FROM        alpine:3.13 as builder

# Change Working Directory
WORKDIR     /app

# Copy Files
COPY        tools/app /app

# Package Installation
RUN         apk update && \
            apk add nodejs npm

# Build Static Files
RUN         npm install && \
            npm run build

# Base Image (Currently Most Stable Version 3.13)
FROM        alpine:3.13 as server

# Package Installation
RUN         apk update && \
            apk add nginx && \
            wget -O /usr/bin/dumb-init https://github.com/Yelp/dumb-init/releases/download/v1.2.5/dumb-init_1.2.5_x86_64 && \
            chmod +x /usr/bin/dumb-init && \
            mkdir -p /var/run/nginx /etc/nginx/conf.d && \
            rm -rf /etc/nginx/conf.d/default.conf

# Copy Files
COPY        --from=builder /app/build /var/www/html
COPY        conf/nginx.conf /tmp/default.conf
COPY        tools/script.sh /tmp/script.sh

# Permission Control
RUN         chmod +x /tmp/script.sh

# Handle Every Signal Correctly by Dumb Init to PID 1
ENTRYPOINT  [ "/usr/bin/dumb-init", "--" ]

# Command to Execute by Entrypoint
CMD         [ "sh", "-c", "/tmp/script.sh" ]
