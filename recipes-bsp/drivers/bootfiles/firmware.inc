RPIFW_DATE ?= "20181120"
SRCREV ?= "91e955e3786a807f4af8ae7e4a4bbf9ec470b843"
RPIFW_SRC_URI ?= "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"
RPIFW_S ?= "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"
SRC_URI[md5sum] = "1ba69f4764f8c34b76037082294c25c7"
SRC_URI[sha256sum] = "8939476badeb1d28adc60b46315f1511cd83c1942fbde5ef2e04c4f1b9591da6"

PV = "${RPIFW_DATE}"
