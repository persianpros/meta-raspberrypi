SUMMARY = "e2-procfs for ${MACHINE}"
SECTION = "base"
PRIORITY = "required"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://${WORKDIR}/git/LICENSE;md5=d32239bcb673463ab874e80d47fae504"

PACKAGE_ARCH = "${MACHINE_ARCH}"

COMPATIBLE_MACHINE = "^(raspberrypi|raspberrypi0|raspberrypi2|raspberrypi3|raspberrypi4)$"

SRCREV = "${AUTOREV}"

PV = "git${SRCPV}"
PKGV = "git${GITPKGV}"

SRC_URI = "git://github.com/OpenVisionE2/rpi-e2-procfs.git;protocol=git"

S = "${WORKDIR}/git/source/e2_procfs"

inherit module machine_kernel_pr gitpkgv

EXTRA_OEMAKE = "KSRC=${STAGING_KERNEL_BUILDDIR}"

do_configure_prepend(){
	sed -i "s/@rpi@/${MACHINE}/" "${S}/e2_procfs_info.c"
	sed -i "s/@RaspberryPi@/${BOX_BRAND}/" "${S}/e2_procfs_info.c"
	sed -i "s/@BCMRPi@/${RPICHIPSET}/" "${S}/e2_procfs_info.c"
}

do_compile() {
	unset CFLAGS CPPFLAGS CXXFLAGS LDFLAGS
	oe_runmake -C "${STAGING_KERNEL_BUILDDIR}" M="${S}" modules
}

do_install() {
	install -d ${D}${nonarch_base_libdir}/modules/${KERNEL_VERSION}/kernel
	install -m 0644 ${S}/e2_procfs.ko ${D}${nonarch_base_libdir}/modules/${KERNEL_VERSION}/kernel/
	install -d ${D}${sysconfdir}/modules-load.d
	echo "e2_procfs" > ${D}${sysconfdir}/modules-load.d/zeprocfs.conf
}

FILES_${PN} += "${sysconfdir}"
