RPIFW_DATE ?= "20190403"
SRCREV ?= "8b12e9904759b85df224f7352662397ec745ba2b"
RPIFW_SRC_URI ?= "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"
RPIFW_S ?= "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"
SRC_URI[md5sum] = "e1307591377189f0276103ddcf01646c"
SRC_URI[sha256sum] = "26267b4b6ff8ffe1a2276876e062d3c25acbeaa5bc9043a500aeef8f0c5bf11a"

PV = "${RPIFW_DATE}"
