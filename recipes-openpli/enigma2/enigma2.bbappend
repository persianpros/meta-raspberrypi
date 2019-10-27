FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI_append_rpi += "file://remote.conf"

do_install_append_rpi() {
	install -d ${D}${sysconfdir}/enigma2
	install -m 0644 ${WORKDIR}/remote.conf \
	${D}${sysconfdir}/enigma2
}
