# !/bin/sh

# Change Configuration Fields into the Environment Variables
sed -i "s/PROMETHEUS_HOST/$PROMETHEUS_HOST/g" /monitor/grafana/conf/provisioning/datasources/datasource.yml
sed -i "s/PROMETHEUS_PORT/$PROMETHEUS_PORT/g" /monitor/grafana/conf/provisioning/datasources/datasource.yml

# Run by Dumb Init
/monitor/grafana/bin/grafana-server
