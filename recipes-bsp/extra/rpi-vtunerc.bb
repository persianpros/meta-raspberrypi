DESCRIPTION = "Creates vtunerc needed things"
SECTION = "base"
LICENSE = "proprietary"

COMPATIBLE_MACHINE = "^(raspberrypi|raspberrypi0|raspberrypi2|raspberrypi3|raspberrypi4)$"

require conf/license/license-gplv2.inc

inherit update-rc.d

SRC_URI = "file://${PN}.sh"

S = "${WORKDIR}"

do_install () {
    install -d ${D}${sysconfdir}/init.d/
    install -m 0755 ${WORKDIR}/${PN}.sh ${D}${sysconfdir}/init.d/
}

FILES_${PN} = "${sysconfdir}"

INITSCRIPT_NAME = "${PN}.sh"
INITSCRIPT_PARAMS = "defaults 08"
