RPIFW_DATE ?= "20200210"
SRCREV = "88afa9a7c54211b1cbed3b78f0e9b74b53c6e6bb"
RPIFW_SRC_URI ?= "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"
RPIFW_S ?= "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"
SRC_URI[md5sum] = "f96b5b301b880eb9f05cd7537b32503e"
SRC_URI[sha256sum] = "f8925f3bd5911049f171ce7a839feca7b067ca7b4b017ecb921b90b0df7afc6c"

PV = "${RPIFW_DATE}+git${SRCREV}"
