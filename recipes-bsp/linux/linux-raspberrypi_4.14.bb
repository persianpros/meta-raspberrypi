FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

LINUX_VERSION ?= "4.14.94"

SRC_URI[md5sum] = "df1b239234d0ad9f95d34584699d451c"
SRC_URI[sha256sum] = "aad015fafe9eeaa332cbcdb889db06e52f04855a9d045fd9a258e67fbc2cd5d2"

SRC_URI = "\
    https://github.com/OpenVisionE2/linux/archive/rpi-4.14.y.tar.gz \
    file://0001-menuconfig-check-lxdiaglog.sh-Allow-specification-of.patch \
    "

require linux-raspberrypi.inc
