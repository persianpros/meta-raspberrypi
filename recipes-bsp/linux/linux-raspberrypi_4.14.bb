FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

LINUX_VERSION ?= "4.14.87"

SRC_URI[md5sum] = "5067ad20bb147dd5d846f894a0b55044"
SRC_URI[sha256sum] = "91ce58dede429767057d21502959391eca3fc38da33434d1bc5fd47db7626f0b"

SRC_URI = "\
    https://github.com/PLi-metas/linux/archive/rpi-4.14.y.tar.gz \
    file://0001-menuconfig-check-lxdiaglog.sh-Allow-specification-of.patch \
    "

require linux-raspberrypi.inc
