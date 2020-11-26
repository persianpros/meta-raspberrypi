RPIFW_DATE = "20201125"

SRCREV = "e15ef4e4fe8be99cd816cec901d977224a1eb07e"

RPIFW_SRC_URI = "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"

SRC_URI[md5sum] = "4b33cd845ce9d42a13abf9a32f802243"
SRC_URI[sha256sum] = "615b0483894874746419112d7871d9fd6bd7e1a92af9b7c615f72148b12e4a50"

RPIFW_S = "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"

PV = "${RPIFW_DATE}+git${SRCREV}"
