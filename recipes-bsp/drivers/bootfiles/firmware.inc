RPIFW_DATE ?= "20190423"
SRCREV ?= "0e0d61b7796775c9827d1f0364a500d2b12aaacb"
RPIFW_SRC_URI ?= "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"
RPIFW_S ?= "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"
SRC_URI[md5sum] = "5cb7f8a8bc33db679358c049c52a8492"
SRC_URI[sha256sum] = "e036f0e606567fd8f7570d10f4e0aa7ecd0fc6afd26bded957f13aada3bccc20"

PV = "${RPIFW_DATE}"
