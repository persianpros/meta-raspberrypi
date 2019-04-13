require linux-raspberrypi.inc

LIC_FILES_CHKSUM = "file://COPYING;md5=bbea815ee2795b2f4230826c0c6b8814"

LINUX_VERSION = "4.19.34"

MACHINE_KERNEL_PR_append = ".6"

SRCREV = "ab8652c03fa081b27de7e28a74c2536cb2aa3e5b"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "93c420f675e52e4d6118fdef60507fd1"
SRC_URI[sha256sum] = "bb2abbd463ea106bc90df7b910e0d97a62ed462b1358e5b561b13354b376534d"
