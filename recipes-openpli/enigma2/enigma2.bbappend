FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

DEPENDS += "${@bb.utils.contains('MACHINE_FEATURES', 'rpi-vision', 'libdvbcsa libnl userland ffmpeg e2-rpihddevice', '', d)}"
RDEPENDS_${PN} += "${@bb.utils.contains('MACHINE_FEATURES', 'rpi-vision', 'libdvbcsa e2-rpihddevice', '', d)}"

SRC_URI_append_rpi += "file://remote.conf"

do_install_append_rpi() {
	install -d ${D}${sysconfdir}/enigma2
	install -m 0644 ${WORKDIR}/remote.conf \
	${D}${sysconfdir}/enigma2
}
