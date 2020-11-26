RPIFW_DATE = "20201123"

SRCREV = "8f13114b9ea29bd004151d4a8afa500b2df721be"

RPIFW_SRC_URI = "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"

SRC_URI[md5sum] = "d3826a3a3bc3654ec7f7d24107740e8d"
SRC_URI[sha256sum] = "f9be0cc177aae7dddaa0a2967d090ea33a95be9dd519d2eee3bc740af8ffb19e"

RPIFW_S = "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"

PV = "${RPIFW_DATE}+git${SRCREV}"
