FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

PV_rpi = "rpi+git${SRCPV}"
PKGV_rpi = "rpi+git${GITPKGV}"

DEPENDS += "${@bb.utils.contains('MACHINE_FEATURES', 'rpi-pli', 'libdvbcsa libnl', '', d)}"

SRC_URI_rpi = "\
	git://github.com/PLi-metas/enigma2-openpli-rpi.git;branch=develop;name=enigma2 \
	git://github.com/PLi-metas/extra_rc_models.git;protocol=git;destsuffix=extra_rc_models;name=extrarcmodels \
	file://remote.conf \
	"

do_install_append_rpi() {
	install -d ${D}/etc/enigma2
	install -m 0644 ${WORKDIR}/remote.conf \
	${D}/etc/enigma2
}
