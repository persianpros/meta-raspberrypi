FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

LINUX_VERSION ?= "4.14.69"

SRC_URI[md5sum] = "16b3461f1256fa4d85b11db7a6c88929"
SRC_URI[sha256sum] = "9a7ba7f9ec749b0653d3a9ec239bea3d14ff4e69748088bb52988469043d7244"

SRC_URI = "\
    https://github.com/PLi-metas/linux/archive/rpi-4.14.y.tar.gz \
    file://0001-menuconfig-check-lxdiaglog.sh-Allow-specification-of.patch \
    "

require linux-raspberrypi.inc
