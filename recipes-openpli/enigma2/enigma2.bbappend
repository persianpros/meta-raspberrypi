FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

PV_rpi = "rpi+git${SRCPV}"
PKGV_rpi = "rpi+git${GITPKGV}"

DEPENDS += "${@bb.utils.contains('MACHINE_FEATURES', 'rpi-pli', 'libdvbcsa libnl userland ffmpeg e2-rpihddevice', '', d)}"
RDEPENDS_${PN} += "${@bb.utils.contains('MACHINE_FEATURES', 'rpi-pli', 'libdvbcsa e2-rpihddevice', '', d)}"

SRC_URI_rpi = "\
	git://github.com/OpenVisionE2/enigma2-openpli-rpi.git;branch=develop;name=enigma2 \
	git://github.com/OpenVisionE2/extra_rc_models.git;protocol=git;destsuffix=extra_rc_models;name=extrarcmodels \
	file://remote.conf \
	"

do_install_append_rpi() {
	install -d ${D}/etc/enigma2
	install -m 0644 ${WORKDIR}/remote.conf \
	${D}/etc/enigma2
}
