require linux-raspberrypi.inc

LINUX_VERSION = "4.19.80"

SRCREV = "a287d34bbec7672af4b685e8c2dcde8e44802e1c"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "68fed630f1275b309656e88cbbb790f0"
SRC_URI[sha256sum] = "a7ad70872a274194378ba2fe49cecd7a33dd8b4daf437adba7d184ee727722e3"
