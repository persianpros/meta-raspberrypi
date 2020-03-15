RPIFW_DATE ?= "20200310"
SRCREV = "9e2193537c48abf8225e02e15e319a209cca558a"
RPIFW_SRC_URI ?= "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"
RPIFW_S ?= "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"
SRC_URI[md5sum] = "4407cab554f518b13e4788fc810b71ed"
SRC_URI[sha256sum] = "fa9b2b40de17a8eb16c25f3db6bcffefdcd870b0d93cd160fb9221333b201d84"

PV = "${RPIFW_DATE}+git${SRCREV}"
