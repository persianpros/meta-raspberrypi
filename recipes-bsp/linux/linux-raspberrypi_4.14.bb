FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

LINUX_VERSION ?= "4.14.98"

SRC_URI[md5sum] = "b578e11e47851bd17de9873b138c9e40"
SRC_URI[sha256sum] = "ab497314a36a9e78494817bc56e318650ec882a04b558777e2b8803170f4be79"

SRC_URI = "\
    https://github.com/OpenVisionE2/linux/archive/rpi-4.14.y.tar.gz \
    file://0001-menuconfig-check-lxdiaglog.sh-Allow-specification-of.patch \
    "

require linux-raspberrypi.inc
