FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

LINUX_VERSION ?= "4.14.76"

SRC_URI[md5sum] = "c5d961fbce97acb84b1b82c71bd0252f"
SRC_URI[sha256sum] = "785525810514bc55802d5c14f0a61079b2e6912235fcd99783e7e2c7dad4670d"

SRC_URI = "\
    https://github.com/PLi-metas/linux/archive/rpi-4.14.y.tar.gz \
    file://0001-menuconfig-check-lxdiaglog.sh-Allow-specification-of.patch \
    "

require linux-raspberrypi.inc
