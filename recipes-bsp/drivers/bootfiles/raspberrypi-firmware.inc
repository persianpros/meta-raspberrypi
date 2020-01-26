RPIFW_DATE ?= "20200122"
SRCREV ?= "01ecfd2ba2b7cf3a2f4aa75ada895ee4a3e729f5"
RPIFW_SRC_URI ?= "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"
RPIFW_S ?= "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"
SRC_URI[md5sum] = "51789392ad23cea9fede49eb81331a07"
SRC_URI[sha256sum] = "31a84340be08be319570a9d1439f25c0e3513fed73065a56aa5dd61dd605d5d9"

PV = "${RPIFW_DATE}+git${SRCREV}"
