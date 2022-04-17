# !/bin/sh

# Run by Dumb Init (It is ok, if target is executed by daemon)
/usr/bin/cadvisor -logtostderr -port=${CADVISOR_PORT} -url_base_prefix=${CADVISOR_URL_BASE_PREFIX}
