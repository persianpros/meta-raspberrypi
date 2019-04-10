require linux-raspberrypi.inc

LIC_FILES_CHKSUM = "file://COPYING;md5=bbea815ee2795b2f4230826c0c6b8814"

LINUX_VERSION = "4.19.34"

MACHINE_KERNEL_PR_append = ".5"

SRCREV = "094718277ef7bfeb8fa0343a361915cea4a3acea"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "e00e37db02ccb20fd06a6ebd4e17a19c"
SRC_URI[sha256sum] = "b2c39c65c477f884711aec4c9024ba0439e59ea46302ff3e83d5e001572ce546"
