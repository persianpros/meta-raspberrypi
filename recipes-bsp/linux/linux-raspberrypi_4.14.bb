FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

LINUX_VERSION ?= "4.14.78"

SRC_URI[md5sum] = "40eb04e32fe7070bd3c0004d604b766b"
SRC_URI[sha256sum] = "6ce7105166c5127237d4ee9d5c646655a314edaa5c2b9ec7a6451fffb0c843fa"

SRC_URI = "\
    https://github.com/PLi-metas/linux/archive/rpi-4.14.y.tar.gz \
    file://0001-menuconfig-check-lxdiaglog.sh-Allow-specification-of.patch \
    "

require linux-raspberrypi.inc
