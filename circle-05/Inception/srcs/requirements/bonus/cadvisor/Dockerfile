# Base Image for Data Collection
FROM        debian:buster

# Package Installation
RUN         apt-get update && \
            apt-get install -y wget curl && \
            wget -O /usr/bin/dumb-init https://github.com/Yelp/dumb-init/releases/download/v1.2.5/dumb-init_1.2.5_x86_64 && \
            chmod +x /usr/bin/dumb-init && \
            curl -L	https://github.com/google/cadvisor/releases/download/v0.37.5/cadvisor --output /usr/bin/cadvisor --silent && \
            chmod +x /usr/bin/cadvisor

# Copy Files
COPY        tools/script.sh /tmp/script.sh

# Permission Control
RUN         chmod +x /tmp/script.sh

# Handle Every Signal Correctly by Dumb Init to PID 1
ENTRYPOINT  [ "/usr/bin/dumb-init", "--" ]

# Command to Execute by Entrypoint
CMD         [ "sh", "-c", "/tmp/script.sh" ]
