FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

LINUX_VERSION ?= "4.14.90"

SRC_URI[md5sum] = "c61dd8cac156a0d1584aad11c972715c"
SRC_URI[sha256sum] = "201989bef5f1000164380bd4db5c4501598f6180e82723d688c20a4c25e1f595"

SRC_URI = "\
    https://github.com/PLi-metas/linux/archive/rpi-4.14.y.tar.gz \
    file://0001-menuconfig-check-lxdiaglog.sh-Allow-specification-of.patch \
    "

require linux-raspberrypi.inc
