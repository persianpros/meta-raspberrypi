FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

LINUX_VERSION ?= "4.14.81"

SRC_URI[md5sum] = "160198d2f919c2e40d0c426874c344a3"
SRC_URI[sha256sum] = "417aa914af030a7cf31744a4196ae7b9c2a44cc2d5298b625b9f372e1cae9d0c"

SRC_URI = "\
    https://github.com/PLi-metas/linux/archive/rpi-4.14.y.tar.gz \
    file://0001-menuconfig-check-lxdiaglog.sh-Allow-specification-of.patch \
    "

require linux-raspberrypi.inc
