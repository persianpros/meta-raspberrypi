require linux-raspberrypi.inc

LIC_FILES_CHKSUM = "file://COPYING;md5=bbea815ee2795b2f4230826c0c6b8814"

LINUX_VERSION = "4.19.32"

MACHINE_KERNEL_PR_append = ".4"

SRCREV = "1026f584d33f27cf0101590a41d2d8a7e51dedd4"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "9d42ef8d4d19466a54fcc061c84e82c6"
SRC_URI[sha256sum] = "ce026aecb101ca14a4680d3eb46dc28b9360869569cc25cad2caa72073c076e3"
