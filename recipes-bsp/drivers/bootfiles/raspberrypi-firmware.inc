RPIFW_DATE ?= "20200116"
SRCREV ?= "be2713bed42381f36c38670d26e9b85780b6233c"
RPIFW_SRC_URI ?= "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"
RPIFW_S ?= "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"
SRC_URI[md5sum] = "344ff74c9b584187de4ec693082ac437"
SRC_URI[sha256sum] = "eea38f16585e7f471cf9d05b19a6a942536e5ad25d845a6905940446f951fb55"

PV = "${RPIFW_DATE}+git${SRCREV}"
