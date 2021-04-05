require linux-raspberrypi.inc

LINUX_VERSION = "${KERNELVERSION}"

SRCREV = "d1fd8a5727908bb677c003d2ae977e9d935a6f94"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "fdee47431c99785563fb0bc55709b3c2"
SRC_URI[sha256sum] = "f4b4bbb56c2b8b7b6f311c1f68efb0c691d03dc16cbc50f3de7ff5a28cc3df44"
