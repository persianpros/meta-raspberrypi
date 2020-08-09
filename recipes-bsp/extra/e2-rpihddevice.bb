SUMMARY = "RaspberryPi rpihddevice for enigma2"
DESCRIPTION = "Enigma2 HD output device for Raspberry Pi. The plugin makes use of the RaspberryPi's VideoCore GPU and provides a lightweight implementation for Enigma2 output device."
SECTION = "multimedia"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://${WORKDIR}/git/COPYING;md5=892f569a555ba9c07a568a7c0c4fa63a"

DEPENDS = "userland ffmpeg freetype jpeg"
RDEPENDS_${PN} = "userland"

COMPATIBLE_MACHINE = "^(raspberrypi|raspberrypi0|raspberrypi2|raspberrypi3|raspberrypi4)$"

inherit gitpkgv pkgconfig autotools-brokensep

SRCREV = "${AUTOREV}"

PV = "git${SRCPV}"
PKGV = "git${GITPKGV}"

SRC_URI = "git://github.com/OpenVisionE2/e2-rpihddevice.git;protocol=git"

S = "${WORKDIR}/git"

ASNEEDED = ""

EXTRA_OEMAKE = '\
	SDKSTAGE="${STAGING_DIR_HOST}" \
'

do_install() {
	oe_runmake DESTDIR=${D} install
}

FILES_${PN} += "\
	${libdir}/* \
"

FILES_${PN}-dev += "\
	$${includedir}/* \
"

FILES_${PN}-dbg += "\
	${libdir}/.debug/* \
