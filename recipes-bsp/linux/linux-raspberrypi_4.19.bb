require linux-raspberrypi.inc

LINUX_VERSION = "4.19.102"

SRCREV = "6567eca5d50ca1d1778e9d2fb8c8926792a72638"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "768e6c4a99255751b610a61ff6a480ce"
SRC_URI[sha256sum] = "e026ac4c7ca89f16ca7700c818935dde13260eacb1d18a29ded61985858de82a"
