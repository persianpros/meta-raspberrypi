require linux-raspberrypi.inc

LINUX_VERSION = "${KERNELVERSION}"

SRCREV = "f943c26bb838ef807216e1f3b41732c5195a7de7"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "745890cb5066a9b9db343c5ac3a1d8b3"
SRC_URI[sha256sum] = "f37918add8def512bf7c5bf630290b2091b654e5d4359ed4fd1eed98243dccd2"
