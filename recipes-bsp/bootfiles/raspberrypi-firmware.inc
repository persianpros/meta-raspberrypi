RPIFW_DATE = "20210305"

SRCREV = "1711f63174c5bfe147cc903af14e99a36938c105"

RPIFW_SRC_URI = "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"

SRC_URI[md5sum] = "b7f515959d092ddc353368486a267a26"
SRC_URI[sha256sum] = "4ea4293a097fc692b36e49d5df951e56b79a8c92bad5011397598ede42e052a0"

RPIFW_S = "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"

PV = "${RPIFW_DATE}+git${SRCREV}"
