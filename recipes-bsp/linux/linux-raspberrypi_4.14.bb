FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

LINUX_VERSION ?= "4.14.77"

SRC_URI[md5sum] = "8fe121b832140ee4da46aa435ba27ad8"
SRC_URI[sha256sum] = "2d070e2a803c0c5e115c2283652e92a8e33df159cda39e40f5f083e7ab3f8f9f"

SRC_URI = "\
    https://github.com/PLi-metas/linux/archive/rpi-4.14.y.tar.gz \
    file://0001-menuconfig-check-lxdiaglog.sh-Allow-specification-of.patch \
    "

require linux-raspberrypi.inc
