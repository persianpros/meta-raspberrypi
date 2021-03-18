RPIFW_DATE = "20210315"

SRCREV = "8717598c7eb443c39c28a4b3a66b4d369ae0a83f"

RPIFW_SRC_URI = "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"

SRC_URI[md5sum] = "7b8562aec81bd244008fc8aad348435c"
SRC_URI[sha256sum] = "a942cc52cabf17661675d0877f39b1159fca2c83d57299d2dde06ad6e39ab0ab"

RPIFW_S = "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"

PV = "${RPIFW_DATE}+git${SRCREV}"
