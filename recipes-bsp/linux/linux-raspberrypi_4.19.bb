require linux-raspberrypi.inc

LINUX_VERSION = "4.19.113"

SRCREV = "4f2a4cc501c428c940549f39d5562e60404ac4f7"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "f56df887bc73557da2f25910eccece66"
SRC_URI[sha256sum] = "97d835a853dcbc0016b26daa618ce7511b9fecb7c4628dcb56667234163d88eb"

SRC_URI += "file://0001-perf-Make-perf-able-to-build-with-latest-libbfd.patch"
