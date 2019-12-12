require linux-raspberrypi.inc

LINUX_VERSION = "4.19.88"

SRCREV = "988cc7beacc150756c3fbe40646afcf8438b741b"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "c9c90bfbb570dc2ed11b4690bc9ea5e4"
SRC_URI[sha256sum] = "d743a92b3d94973876dd7513044d4d8b119091ab8e66fcee3d0623e1c09d1d6d"
