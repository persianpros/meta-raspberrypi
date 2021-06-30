RPIFW_DATE = "20210629"

SRCREV = "19272ccd69049aaf42c78a235a0bf37dbabd5ea7"

RPIFW_SRC_URI = "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"

SRC_URI[md5sum] = "bcc10a6e6e052278e352189bb3d0be46"
SRC_URI[sha256sum] = "accd328f21c11a643b358c647c0c532c8f97b0167b12d24d9f14aa71be526f0b"

RPIFW_S = "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"

PV = "${RPIFW_DATE}+git${SRCREV}"
