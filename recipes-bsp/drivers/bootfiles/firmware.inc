RPIFW_DATE ?= "20190225"
SRCREV ?= "f84820ed7fcfd0f0d364e3d47cdbc83215596b2c"
RPIFW_SRC_URI ?= "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"
RPIFW_S ?= "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"
SRC_URI[md5sum] = "bfd5bf2cd433eef07ae1bb4df30f1ca0"
SRC_URI[sha256sum] = "4da4eaaf5c89124f292f68f627d978eb3cd6d7832275d58413987fe4855c3391"

PV = "${RPIFW_DATE}"
