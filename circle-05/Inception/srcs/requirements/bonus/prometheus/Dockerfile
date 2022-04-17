# Base Image for Data Collection
FROM        debian:buster

# Package Installation
RUN         apt-get update && \
            apt-get install -y wget prometheus && \
            wget -O /usr/bin/dumb-init https://github.com/Yelp/dumb-init/releases/download/v1.2.5/dumb-init_1.2.5_x86_64 && \
            chmod +x /usr/bin/dumb-init

# Copy Files
COPY        conf/prometheus.yml /tmp/prometheus.yml
COPY        tools/script.sh /tmp/script.sh

# Permission Control
RUN         chmod +x /tmp/script.sh && \
            chmod +x /tmp/prometheus.yml

# Handle Every Signal Correctly by Dumb Init to PID 1
ENTRYPOINT  [ "/usr/bin/dumb-init", "--" ]

# Command to Execute by Entrypoint
CMD         [ "sh", "-c", "/tmp/script.sh" ]
