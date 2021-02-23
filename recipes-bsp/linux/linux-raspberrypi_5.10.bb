require linux-raspberrypi.inc

LINUX_VERSION = "${KERNELVERSION}"

SRCREV = "12fdeddcde1ce67177ae0e13931ff24944015625"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "eb149c0bbcdc1eef6898a9a2c468fef9"
SRC_URI[sha256sum] = "e4dcdb2ee22ffeae85c4f3916d60a5065f7068f852b76a530f5604628d4e60ba"
