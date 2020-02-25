require linux-raspberrypi.inc

LINUX_VERSION = "4.19.105"

SRCREV = "9634b843e28cae9df42b08ea37e136822c339a3f"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "545931f65600e893579913afc5b2baf0"
SRC_URI[sha256sum] = "4a51c3dbad394d6dd39a5da2e041d678a0db4551c375246904b16dd203abcf13"
