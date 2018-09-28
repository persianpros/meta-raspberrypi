FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

LINUX_VERSION ?= "4.14.72"

SRC_URI[md5sum] = "faf1564492cb7f7463cc9c316d11eb25"
SRC_URI[sha256sum] = "151752d9bf097a5fb74f09bab04ee359e004f1b3f2d26f042677faf4ba5d3206"

SRC_URI = "\
    https://github.com/PLi-metas/linux/archive/rpi-4.14.y.tar.gz \
    file://0001-menuconfig-check-lxdiaglog.sh-Allow-specification-of.patch \
    "

require linux-raspberrypi.inc
