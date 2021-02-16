require linux-raspberrypi.inc

LINUX_VERSION = "${KERNELVERSION}"

SRCREV = "71db517a9e1e0888f06f1be3fcd7df200ba64373"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "6c93a9a5d4a2f1ea7c994bf9140d66c3"
SRC_URI[sha256sum] = "b2f2dc7f1e5a0e22025477f290bdd8de471b828611dfe7561fcb3972c104c676"
