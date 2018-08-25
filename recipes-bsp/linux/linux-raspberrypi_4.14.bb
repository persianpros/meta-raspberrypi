FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

LINUX_VERSION ?= "4.14.66"

SRC_URI[md5sum] = "deafb509257b5ff5c92a725fff5d8484"
SRC_URI[sha256sum] = "4fe14d9e9411fa8acf5a83630e6fc1d479f728ef7f514c14ed8b1a5ff160ea09"

SRC_URI = "\
    https://github.com/PLi-metas/linux/archive/rpi-4.14.y.tar.gz \
    file://0001-menuconfig-check-lxdiaglog.sh-Allow-specification-of.patch \
    "

require linux-raspberrypi.inc
