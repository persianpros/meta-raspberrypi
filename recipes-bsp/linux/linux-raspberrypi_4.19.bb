require linux-raspberrypi.inc

LIC_FILES_CHKSUM = "file://COPYING;md5=bbea815ee2795b2f4230826c0c6b8814"

LINUX_VERSION = "4.19.36"

MACHINE_KERNEL_PR_append = ".7"

SRCREV = "210f0d39438017f3b4e9a92cf4e2ccac8be3e795"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "f9175a53d8099703597aafb9c0178e66"
SRC_URI[sha256sum] = "d018a55a891e167ce04fa52f3d00aa256de7ed86296c19c37b3a2f0a0a9ff6f8"
