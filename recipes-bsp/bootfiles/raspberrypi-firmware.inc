RPIFW_DATE = "20210223"

SRCREV = "cb8cbb2c05c953b87aeb22276e4797f77494c0ef"

RPIFW_SRC_URI = "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"

SRC_URI[md5sum] = "a6c1ae246416a4296299cad840edf5a7"
SRC_URI[sha256sum] = "e6e1a5856e91b61fbc74f0b4e5ebb3d53806c0e87baacba43014aa7c1bfbfcda"

RPIFW_S = "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"

PV = "${RPIFW_DATE}+git${SRCREV}"
