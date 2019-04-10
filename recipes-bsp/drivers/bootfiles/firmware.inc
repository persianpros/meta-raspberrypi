RPIFW_DATE ?= "20190409"
SRCREV ?= "9ce09b817068671faddc56b5400c1b33232eabcf"
RPIFW_SRC_URI ?= "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"
RPIFW_S ?= "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"
SRC_URI[md5sum] = "66bded339660496c12ab5b8d0ed604a2"
SRC_URI[sha256sum] = "0e49f946d964f61f79d475fa9ccb81fc73161e4b3edbc2b2224dc91124f7e117"

PV = "${RPIFW_DATE}"
