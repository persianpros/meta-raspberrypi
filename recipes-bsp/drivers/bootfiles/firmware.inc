RPIFW_DATE ?= "20181211"
SRCREV ?= "de8589ef09567f12508faedc8ced3046b078e9b5"
RPIFW_SRC_URI ?= "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"
RPIFW_S ?= "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"
#SRC_URI[md5sum] = "52a8bc8a0a759777cf25c7a89a7634dc"
#SRC_URI[sha256sum] = "40223ffffeeb0caf35568fd91a7698ad47e9c3a5c522d410ffee0a656cbb955c"

PV = "${RPIFW_DATE}"
