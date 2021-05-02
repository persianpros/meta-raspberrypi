RPIFW_DATE = "20210430"

SRCREV = "1a46874494146f470d7a61b0b6f4f15a07dd8b35"

RPIFW_SRC_URI = "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"

SRC_URI[md5sum] = "2ff1c9abf31b6096b797e8510707bdb1"
SRC_URI[sha256sum] = "ac4e6bd0741e2cb1b99042af12c3ef4adc00ba9c9147cdd91b1ae4faf0928952"

RPIFW_S = "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"

PV = "${RPIFW_DATE}+git${SRCREV}"
