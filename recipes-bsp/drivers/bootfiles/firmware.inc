RPIFW_DATE ?= "20181218"
SRCREV ?= "1ea87818b323d08e7bc8e74f930952f36f2f61f4"
RPIFW_SRC_URI ?= "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"
RPIFW_S ?= "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"
SRC_URI[md5sum] = "0f9b73cbe04102d17dde2219a85fe5f1"
SRC_URI[sha256sum] = "df4ecfa3c5dbdb9831ab3f0bf4e457cbfb84014d57c2ef7df0d9c0a8a5fc7ea3"

PV = "${RPIFW_DATE}"
