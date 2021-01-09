require linux-raspberrypi.inc

LINUX_VERSION = "${KERNELVERSION}"

SRCREV = "bcf09c55a208f82aad1b20e55bdcb11dc46e048e"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "50a9b83e971db1488c409f24c43c79c1"
SRC_URI[sha256sum] = "dc90eced1b10f65e8da22da5fa1664a9e943f574ccc4740063dfca5412ec7180"
