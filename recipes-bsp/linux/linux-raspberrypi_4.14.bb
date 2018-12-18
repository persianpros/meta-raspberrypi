FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

LINUX_VERSION ?= "4.14.89"

SRC_URI[md5sum] = "a4d575f3b0b6468046c2b7a711fe8931"
SRC_URI[sha256sum] = "f2d4677d5697791fbd666f7b4b17ad72acec1ad6449629ddacf037b8b91163ba"

SRC_URI = "\
    https://github.com/PLi-metas/linux/archive/rpi-4.14.y.tar.gz \
    file://0001-menuconfig-check-lxdiaglog.sh-Allow-specification-of.patch \
    "

require linux-raspberrypi.inc
