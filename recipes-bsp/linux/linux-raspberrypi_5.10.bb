require linux-raspberrypi.inc

LINUX_VERSION = "${KERNELVERSION}"

SRCREV = "13c43880f2ee6db7d26949cb6a3e8db1a4b76736"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "d7be2334df48ecbe08841cf43d76f7dc"
SRC_URI[sha256sum] = "cfc1e54102b66719ad8f3e6f97baa4ddc46873ba82a130c481619a705901b1da"
