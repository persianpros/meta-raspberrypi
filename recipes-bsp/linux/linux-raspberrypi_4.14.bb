FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

LINUX_VERSION ?= "4.14.97"

SRC_URI[md5sum] = "c1a56d1820be687984acb571f474927d"
SRC_URI[sha256sum] = "ddddf69ee930fa6f8ddcb039d6efaf14fc22653b76bc531e17f40062789b6c25"

SRC_URI = "\
    https://github.com/OpenVisionE2/linux/archive/rpi-4.14.y.tar.gz \
    file://0001-menuconfig-check-lxdiaglog.sh-Allow-specification-of.patch \
    "

require linux-raspberrypi.inc
