FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI_append += " \
	file://lirc.patch \
	file://remote.conf \
"

do_install_append() {
	install -d  ${D}/etc/enigma2
	install -m 0644 ${WORKDIR}/remote.conf \
	${D}/etc/enigma2
}
