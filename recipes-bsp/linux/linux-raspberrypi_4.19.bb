FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

LINUX_VERSION ?= "4.19.25"

SRC_URI[md5sum] = "9cbb5a5ed937f7d1606d408ba6072caa"
SRC_URI[sha256sum] = "fc7154a6ae0ee0a9073d2e2d918c247de98e6c10ff61534f5769eca3cd7b0b9b"

SRC_URI = "https://github.com/OpenVisionE2/linux/archive/rpi-4.19.y.tar.gz"

require linux-raspberrypi.inc
