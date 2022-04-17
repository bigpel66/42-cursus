# !/bin/sh

# Change Configuration Fields into the Environment Variables
sed -i "s/CADVISOR_HOST/$CADVISOR_HOST/g" /tmp/prometheus.yml
sed -i "s/CADVISOR_PORT/$CADVISOR_PORT/g" /tmp/prometheus.yml
sed -i "s/PROMETHEUS_PORT/$PROMETHEUS_PORT/g" /tmp/prometheus.yml

# Copy Configuration File
cp /tmp/prometheus.yml /etc/prometheus/prometheus.yml

# Run by Dumb Init
prometheus --config.file=/etc/prometheus/prometheus.yml --storage.tsdb.path=/monitor/prometheus --storage.tsdb.retention=200h --web.listen-address=:${PROMETHEUS_PORT}
