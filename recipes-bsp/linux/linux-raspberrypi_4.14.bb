FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

LINUX_VERSION ?= "4.14.73"

SRC_URI[md5sum] = "ef880bd6287e3ee8bd85af29d5ec931d"
SRC_URI[sha256sum] = "4408a5b3527f75d36b279eb1b84ab9ed9ea632a234e2cf69beed9727154ce3ba"

SRC_URI = "\
    https://github.com/PLi-metas/linux/archive/rpi-4.14.y.tar.gz \
    file://0001-menuconfig-check-lxdiaglog.sh-Allow-specification-of.patch \
    "

require linux-raspberrypi.inc
