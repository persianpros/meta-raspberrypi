require linux-raspberrypi.inc

LINUX_VERSION = "4.19.86"

SRCREV = "a4724c87014e2fe11904d17447ad00b5ee177b1f"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "c71d5cddb94ca6ace2b8774942ffbf8a"
SRC_URI[sha256sum] = "255c34fa874a1917de48fde3c663d730630fe7bdb469b721bce1756f5d93bad3"
