require linux-raspberrypi.inc

LINUX_VERSION = "${KERNELVERSION}"

SRCREV = "1ea02333d959ea9005eb7215a89add2a6da3b25a"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "3efa9b0bb4b4c97c6ac3da326f0e5c74"
SRC_URI[sha256sum] = "111756ab785131753964cee2b3eac197cb630a05063aaa2aca5f9b4c71dd547a"
