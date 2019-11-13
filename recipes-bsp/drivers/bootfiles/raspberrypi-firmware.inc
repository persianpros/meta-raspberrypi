RPIFW_DATE ?= "20191112"
SRCREV ?= "2d131ae9b8f41266adc7f1b1a62d7417664c00eb"
RPIFW_SRC_URI ?= "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"
RPIFW_S ?= "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"
SRC_URI[md5sum] = "280d865ff5f25e9952121dfccb87062c"
SRC_URI[sha256sum] = "bc375053647b627e60600559cd091e85f09adaa24db1b44722801bf5ef85ba1f"

PV = "${RPIFW_DATE}+git${SRCREV}"
