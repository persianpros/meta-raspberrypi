RPIFW_DATE ?= "20191129"
SRCREV ?= "601d36df3aa541560e4cf9b571105d20db2b4b7c"
RPIFW_SRC_URI ?= "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"
RPIFW_S ?= "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"
SRC_URI[md5sum] = "9089a6bfcee3866d71176b6bbc590e89"
SRC_URI[sha256sum] = "5c34c849a8273161947f49ca834e2ec241d333ca230b214fe3d3c99f31b28a1f"

PV = "${RPIFW_DATE}+git${SRCREV}"
