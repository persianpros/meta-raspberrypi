RPIFW_DATE ?= "20181221"
SRCREV ?= "e1bd9b0b8cda901ee9b23cbb8b3334cde71320a7"
RPIFW_SRC_URI ?= "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"
RPIFW_S ?= "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"
SRC_URI[md5sum] = "816aaa39d09ad54616b7c690b20b7cd6"
SRC_URI[sha256sum] = "58dc9d1080582964943b509ed9444602ce7fb50c1124199d3f06a5b121aa0706"

PV = "${RPIFW_DATE}"
