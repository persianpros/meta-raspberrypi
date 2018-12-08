FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

LINUX_VERSION ?= "4.14.86"

SRC_URI[md5sum] = "4dfea1d078b9d1836e48b84bf6d9d666"
SRC_URI[sha256sum] = "c7f2cae9f191c875be1bb52431d60bc067ec5513ec9ab33fb9c34223b797a058"

SRC_URI = "\
    https://github.com/PLi-metas/linux/archive/rpi-4.14.y.tar.gz \
    file://0001-menuconfig-check-lxdiaglog.sh-Allow-specification-of.patch \
    "

require linux-raspberrypi.inc
