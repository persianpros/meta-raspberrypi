FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

LINUX_VERSION ?= "4.14.79"

SRC_URI[md5sum] = "ba913ab80b1b90ce48ec33bfa4f764dd"
SRC_URI[sha256sum] = "2000d8d47978682f2234569efec4c0684ebcf50e0cb2016034eb3ea16f43a5cf"

SRC_URI = "\
    https://github.com/PLi-metas/linux/archive/rpi-4.14.y.tar.gz \
    file://0001-menuconfig-check-lxdiaglog.sh-Allow-specification-of.patch \
    "

require linux-raspberrypi.inc
