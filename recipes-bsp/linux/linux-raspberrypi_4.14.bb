FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

LINUX_VERSION ?= "4.14.71"

SRC_URI[md5sum] = "c6e165087c5fbc6df0c02ad88737c131"
SRC_URI[sha256sum] = "5d04bd26ca7eb4cd57eea176d5f655a4cd7d0f9958e781ac90ba1839bf9aced8"

SRC_URI = "\
    https://github.com/PLi-metas/linux/archive/rpi-4.14.y.tar.gz \
    file://0001-menuconfig-check-lxdiaglog.sh-Allow-specification-of.patch \
    "

require linux-raspberrypi.inc
