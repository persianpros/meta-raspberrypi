FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

LINUX_VERSION ?= "4.14.98"

SRC_URI[md5sum] = "e971505e686342bb8d6090d14ddf13fd"
SRC_URI[sha256sum] = "52a38e85ff4bedfe40f2683b7bf7de3826611965fe341dfefa55b9bce1c34502"

SRC_URI = "\
    https://github.com/OpenVisionE2/linux/archive/rpi-4.14.y.tar.gz \
    file://0001-menuconfig-check-lxdiaglog.sh-Allow-specification-of.patch \
    "

require linux-raspberrypi.inc
