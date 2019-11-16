RPIFW_DATE ?= "20191114"
SRCREV ?= "b9f83b14a8f8ea11e4cc509da037d05836efa00f"
RPIFW_SRC_URI ?= "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"
RPIFW_S ?= "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"
SRC_URI[md5sum] = "92d30f882dc79ca36165e194e51c550d"
SRC_URI[sha256sum] = "e62fa9873a6c17ccbe6302dbd15634d4f23e62087e92c487c6dc3286a94d5b08"

PV = "${RPIFW_DATE}+git${SRCREV}"
