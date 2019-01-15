FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

LINUX_VERSION ?= "4.14.93"

SRC_URI[md5sum] = "401bceffb23c9bff4901aa13aae200bf"
SRC_URI[sha256sum] = "f034a5d9ce143cbff125119d249de8fe2a8a004044ebc5ddb47807203a23568e"

SRC_URI = "\
    https://github.com/OpenVisionE2/linux/archive/rpi-4.14.y.tar.gz \
    file://0001-menuconfig-check-lxdiaglog.sh-Allow-specification-of.patch \
    "

require linux-raspberrypi.inc
