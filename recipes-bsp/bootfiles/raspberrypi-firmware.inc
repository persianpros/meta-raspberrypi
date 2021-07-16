RPIFW_DATE = "20210716"

SRCREV = "4be1d21062e8b646e588e104a5a5d414996a48b2"

RPIFW_SRC_URI = "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"

SRC_URI[md5sum] = "7d5cc6374d0c851a2226fc92cf070e83"
SRC_URI[sha256sum] = "7309e460166ae623cbef803b041767c9f8adc3f536800fc883280ba955706dc2"

RPIFW_S = "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"

PV = "${RPIFW_DATE}+git${SRCREV}"
