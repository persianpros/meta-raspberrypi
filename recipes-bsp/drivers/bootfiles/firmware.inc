RPIFW_DATE ?= "20181105"
SRCREV ?= "55e591283f456ab9cebd9c31aaef4939f814880d"
RPIFW_SRC_URI ?= "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"
RPIFW_S ?= "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"
SRC_URI[md5sum] = "4f1f96a1b1cb1ad7b947a8821260e938"
SRC_URI[sha256sum] = "a0595532ac36d4e550b128a94148b50fd92bf247a53e3298e2e0144c4a732382"

PV = "${RPIFW_DATE}"
