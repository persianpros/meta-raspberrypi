RPIFW_DATE ?= "20190308"
SRCREV ?= "fd15e0700e45d9b7db83e30696aba299b9f2f31d"
RPIFW_SRC_URI ?= "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"
RPIFW_S ?= "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"
SRC_URI[md5sum] = "4989bb114dda86db1ca3f91c17e0e4a5"
SRC_URI[sha256sum] = "a95f3c46a8365cd66eca23c1ba7e9110584486dc1341d3d798c7241921e787dc"

PV = "${RPIFW_DATE}"
