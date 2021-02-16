RPIFW_DATE = "20210216"

SRCREV = "ba6259246c702b04ea56ff1034325e476d460ae8"

RPIFW_SRC_URI = "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"

SRC_URI[md5sum] = "fd57a31d8af83e92956cca235455330c"
SRC_URI[sha256sum] = "719d0f1203700619ba263c65e86ba7e5cba14c3a83b7f381b3a5e9a4e4ccae67"

RPIFW_S = "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"

PV = "${RPIFW_DATE}+git${SRCREV}"
