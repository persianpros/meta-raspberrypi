FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

LINUX_VERSION ?= "4.14.67"

SRC_URI[md5sum] = "d4c529a57eaa1847fbc229afee17410e"
SRC_URI[sha256sum] = "863c897f0b75154638c60e84b73aee06d1d54a8bee232aec02c7d33f38f5700b"

SRC_URI = "\
    https://github.com/PLi-metas/linux/archive/rpi-4.14.y.tar.gz \
    file://0001-menuconfig-check-lxdiaglog.sh-Allow-specification-of.patch \
    "

require linux-raspberrypi.inc
