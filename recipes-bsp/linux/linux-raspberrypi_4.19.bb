require linux-raspberrypi.inc

LIC_FILES_CHKSUM = "file://COPYING;md5=bbea815ee2795b2f4230826c0c6b8814"

LINUX_VERSION = "4.19.27"

MACHINE_KERNEL_PR_append = ".2"

SRCREV = "089ae6dda1d91d39f21e223a6413d552be798bce"

S_rpi = "${WORKDIR}/linux-089ae6dda1d91d39f21e223a6413d552be798bce"

SRC_URI[md5sum] = "a5facfaa00f57d0eb4f35065ad7a332c"
SRC_URI[sha256sum] = "b36d24c01cb4b6f30d63536396e95f07b0269c8e775938b9b4a21fdde12f989a"
