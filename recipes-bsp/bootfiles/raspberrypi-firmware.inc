RPIFW_DATE = "20210126"

SRCREV = "5bafb302877a08885a526fe081738548dd698ab8"

RPIFW_SRC_URI = "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"

SRC_URI[md5sum] = "ccd46f3441ff906396da04d62143b755"
SRC_URI[sha256sum] = "abfd7047e7cfdaeaf8d10f319a75c88fdf2c1e8814f959e13bc354e6bde6e064"

RPIFW_S = "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"

PV = "${RPIFW_DATE}+git${SRCREV}"
