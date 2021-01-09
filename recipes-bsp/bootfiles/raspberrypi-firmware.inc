RPIFW_DATE = "20210108"

SRCREV = "e542b67e7f5487d222aa39b3e9ee780a5dbbb9eb"

RPIFW_SRC_URI = "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"

SRC_URI[md5sum] = "f8f9a95e079fb05f649b1c6d06660e8a"
SRC_URI[sha256sum] = "cc1d657085770b39bc1b6338177952127364fc91371f93578441d0d655db387e"

RPIFW_S = "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"

PV = "${RPIFW_DATE}+git${SRCREV}"
