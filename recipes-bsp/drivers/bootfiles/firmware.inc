RPIFW_DATE ?= "20190123"
SRCREV ?= "81cca1a9380c828299e884dba5efd0d4acb39e8d"
RPIFW_SRC_URI ?= "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"
RPIFW_S ?= "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"
SRC_URI[md5sum] = "e5f04cc8700888458f472862c4d702da"
SRC_URI[sha256sum] = "f1d631920ed4ae15f368ba7b8b3caa4ed604f5223372cc6debbd39a101eb8d74"

PV = "${RPIFW_DATE}"
