FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

LINUX_VERSION ?= "4.14.84"

SRC_URI[md5sum] = "446bc5617cfd06bca7ee0702ee3a0b47"
SRC_URI[sha256sum] = "0705b49466c25150eae21fa54ad5d724226f3b39356cff29d215eb21aeb93d7a"

SRC_URI = "\
    https://github.com/PLi-metas/linux/archive/rpi-4.14.y.tar.gz \
    file://0001-menuconfig-check-lxdiaglog.sh-Allow-specification-of.patch \
    "

require linux-raspberrypi.inc
