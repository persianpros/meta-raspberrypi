require linux-raspberrypi.inc

LINUX_VERSION = "${KERNELVERSION}"

SRCREV = "7fb9d006d3ff3baf2e205e0c85c4e4fd0a64fcd0"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "20c58915198b68f58c5ac0cbbab8217e"
SRC_URI[sha256sum] = "e70ecd479ea323d00ed441f1888256687dec96b0f4098585b1646f2d5d930eff"
