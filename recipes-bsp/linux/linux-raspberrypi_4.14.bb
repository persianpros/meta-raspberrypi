FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

LINUX_VERSION ?= "4.14.70"

SRC_URI[md5sum] = "c2a6b30fc54c1f93204eaddc2fc00f92"
SRC_URI[sha256sum] = "47691ee5ababe049fff680049801e37aad6fb81a24a8bbf841b3f68ac60dbfa0"

SRC_URI = "\
    https://github.com/PLi-metas/linux/archive/rpi-4.14.y.tar.gz \
    file://0001-menuconfig-check-lxdiaglog.sh-Allow-specification-of.patch \
    "

require linux-raspberrypi.inc
