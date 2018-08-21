FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

LINUX_VERSION ?= "4.9.80"

SRC_URI[md5sum] = "61765ed7d8e96ceafe24b539188c59ee"
SRC_URI[sha256sum] = "92fd843f172ba69def66ae6e06346630ad97c9c0909d5e1a7f0f1753ada553ef"

SRC_URI = "https://github.com/PLi-metas/linux/archive/rpi-4.9.y.tar.gz"

require linux-raspberrypi.inc

# A LOADADDR is needed when building a uImage format kernel. This value is not
# set by default in rpi-4.8.y and later branches so we need to provide it
# manually. This value unused if KERNEL_IMAGETYPE is not uImage.
KERNEL_EXTRA_ARGS += "LOADADDR=0x00008000"
