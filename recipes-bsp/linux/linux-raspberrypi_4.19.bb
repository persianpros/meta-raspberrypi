require linux-raspberrypi.inc

LINUX_VERSION = "4.19.81"

SRCREV = "bbdf44a11a065ebb2aa2ed5690b82287739b471d"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "0ba624c5e41ca072dd3af6502494eb3d"
SRC_URI[sha256sum] = "b9ebdfc4622613e919d72089445ab715e2e438a31ecd1bdb357953bed0be1512"
