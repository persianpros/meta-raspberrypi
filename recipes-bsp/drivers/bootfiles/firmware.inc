RPIFW_DATE ?= "20190114"
SRCREV ?= "f0694b1ec66a88abab334c460f212ebf19ab7cd8"
RPIFW_SRC_URI ?= "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"
RPIFW_S ?= "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"
SRC_URI[md5sum] = "18f45ebfb42fdfb609c69674fee14d99"
SRC_URI[sha256sum] = "03b38adf9e04163ef3da1d8135a0e3f2393489738b99b55fd6113dcf48c4e719"

PV = "${RPIFW_DATE}"
