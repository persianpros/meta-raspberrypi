FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

LINUX_VERSION ?= "4.14.91"

SRC_URI[md5sum] = "de976aecd91b5adad6c20c0b29567027"
SRC_URI[sha256sum] = "84232473140b64a026a327f2613ab2f5ba99aa7c28c832893f48d45b08535b3a"

SRC_URI = "\
    https://github.com/OpenVisionE2/linux/archive/rpi-4.14.y.tar.gz \
    file://0001-menuconfig-check-lxdiaglog.sh-Allow-specification-of.patch \
    "

require linux-raspberrypi.inc
