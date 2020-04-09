RPIFW_DATE = "20200407"

SRCREV = "dd8cbec5a6d27090e5eb080e13d83c35fdd759f7"

RPIFW_SRC_URI = "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"

SRC_URI[md5sum] = "7f037781877ab4e75af6253a2994ac44"
SRC_URI[sha256sum] = "06e6cd4df5f6543a962a434668883e50f33e22a1f4964ece63432c947291cf50"

RPIFW_S = "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"

PV = "${RPIFW_DATE}+git${SRCREV}"
