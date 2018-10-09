FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

LINUX_VERSION ?= "4.14.74"

SRC_URI[md5sum] = "d9534728efd02e7e619a0619c6c85c9e"
SRC_URI[sha256sum] = "add93ad480e35a69279ea31bc757c967ec50f9c910d8602916b53f89577984c7"

SRC_URI = "\
    https://github.com/PLi-metas/linux/archive/rpi-4.14.y.tar.gz \
    file://0001-menuconfig-check-lxdiaglog.sh-Allow-specification-of.patch \
    "

require linux-raspberrypi.inc
