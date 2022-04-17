# Base Image (Currently Most Stable Version 3.13)
FROM        alpine:3.13

# Package Installation
RUN         apk update && \
            apk add curl libc6-compat && \
            mkdir -p /monitor/grafana && \
            wget -O /usr/bin/dumb-init https://github.com/Yelp/dumb-init/releases/download/v1.2.5/dumb-init_1.2.5_x86_64 && \
            chmod +x /usr/bin/dumb-init && \
            curl -L https://dl.grafana.com/enterprise/release/grafana-enterprise-8.2.2.linux-amd64.tar.gz -o /tmp/grafana-enterprise-8.2.2.linux-amd64.tar.gz && \
            tar -zxvf /tmp/grafana-enterprise-8.2.2.linux-amd64.tar.gz -C /monitor/grafana && \
            mv /monitor/grafana/grafana-8.2.2/* /monitor/grafana/ && \
            rm -rf /monitor/grafana/grafana-8.2.2/ && \
            mkdir -p /monitor/grafana/dashboards /monitor/grafana/conf/provisioning /monitor/grafana/conf/provisioning/datasources /monitor/grafana/conf/provisioning/dashboards

# Copy Files
COPY        conf/custom.ini /monitor/grafana/conf/custom.ini
COPY        conf/datasource.yml /monitor/grafana/conf/provisioning/datasources/datasource.yml
COPY        conf/dashboard.yml /monitor/grafana/conf/provisioning/dashboards/dashboard.yml
COPY        conf/container.json /monitor/grafana/dashboards/container.json
COPY        tools/script.sh /tmp/script.sh

# Permission Control
RUN         chmod +x /tmp/script.sh

# Change Working Directory to Read Configuration File
WORKDIR     /monitor/grafana

# Handle Every Signal Correctly by Dumb Init to PID 1
ENTRYPOINT  [ "/usr/bin/dumb-init", "--" ]

# Command to Execute by Entrypoint
CMD         [ "sh", "-c", "/tmp/script.sh" ]
