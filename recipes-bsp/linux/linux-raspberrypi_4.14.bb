FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

LINUX_VERSION ?= "4.14.92"

SRC_URI[md5sum] = "11b11b9e20b140bdf0f269345f972287"
SRC_URI[sha256sum] = "a6e3a4614e7e34098250c5797b326c5c4aa8b282a0c8b61117facc570acba1b8"

SRC_URI = "\
    https://github.com/OpenVisionE2/linux/archive/rpi-4.14.y.tar.gz \
    file://0001-menuconfig-check-lxdiaglog.sh-Allow-specification-of.patch \
    "

require linux-raspberrypi.inc
