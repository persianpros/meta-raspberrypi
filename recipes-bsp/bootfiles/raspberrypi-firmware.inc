RPIFW_DATE = "20210525"

SRCREV = "fb0bfa6a669745578041e838fc73cc17e8c543c9"

RPIFW_SRC_URI = "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"

SRC_URI[md5sum] = "a757513cfd5a2064bf893a619531fd71"
SRC_URI[sha256sum] = "0bdf7e4e0c142020dc4c2642cc641b1490fac4b2989f5f5f2f246a9e0e3269af"

RPIFW_S = "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"

PV = "${RPIFW_DATE}+git${SRCREV}"
