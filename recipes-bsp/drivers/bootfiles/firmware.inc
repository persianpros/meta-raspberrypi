RPIFW_DATE ?= "20190327"
SRCREV ?= "3dde44c13f17cb34697ef8f867bab147125d5a25"
RPIFW_SRC_URI ?= "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"
RPIFW_S ?= "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"
SRC_URI[md5sum] = "90d8ac395b448f98c3a40370a72142a1"
SRC_URI[sha256sum] = "a0a74840c5d2e939b909f86040353cd689b329df9273694fcdfb97c27b840276"

PV = "${RPIFW_DATE}"
