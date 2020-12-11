RPIFW_DATE = "20201208"

SRCREV = "919aee0ed75f7db48a38b8b96c13228a7584cfd7"

RPIFW_SRC_URI = "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"

SRC_URI[md5sum] = "d3407d589999647ad1dc481dfae70549"
SRC_URI[sha256sum] = "ed800d01810761c06ec9dbc76d05ec303924275e0abf82555931c3a666379ae9"

RPIFW_S = "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"

PV = "${RPIFW_DATE}+git${SRCREV}"
