RPIFW_DATE = "20210507"

SRCREV = "d9c382e0f3a546e9da153673dce5dd4ba1200994"

RPIFW_SRC_URI = "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"

SRC_URI[md5sum] = "933845e006672b242b15680ee494e623"
SRC_URI[sha256sum] = "3dd57730399b0bc12d99a0bcaca9fcbd54514486bf554597221316e3552d0e6e"

RPIFW_S = "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"

PV = "${RPIFW_DATE}+git${SRCREV}"
