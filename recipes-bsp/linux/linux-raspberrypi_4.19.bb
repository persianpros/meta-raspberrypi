require linux-raspberrypi.inc

LINUX_VERSION = "4.19.85"

SRCREV = "c42554e866307ec594ed4d109df900aeccd63a87"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "ffa2a124f818f57240d40d1db2c6b507"
SRC_URI[sha256sum] = "9accc00d92d1d6015765b4d3d4670a8b153017fdc109b590f3365823688e9703"
