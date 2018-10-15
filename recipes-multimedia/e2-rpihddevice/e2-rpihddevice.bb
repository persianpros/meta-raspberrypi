SUMMARY = "rpihddevice for enigma2"
DESCRIPTION = "Enigma2 HD output device for Raspberry Pi. The plugin makes use of the RaspberryPi's VideoCore GPU and provides a lightweight implementation for Enigma2 output device."
SECTION = "multimedia"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://${WORKDIR}/git/COPYING;md5=892f569a555ba9c07a568a7c0c4fa63a"

RDEPENDS_${PN} = "userland ffmpeg libav freetype"

COMPATIBLE_MACHINE = "raspberrypi|raspberrypi0|raspberrypi2|raspberrypi3"

inherit gitpkgv

SRCREV = "${AUTOREV}"

PV = "1.0+git${SRCPV}"
PKGV = "1.0+git${GITPKGV}"

SRC_URI = "git://github.com/PLi-metas/e2-rpihddevice.git;protocol=git"

S = "${WORKDIR}/git"

inherit autotools-brokensep
