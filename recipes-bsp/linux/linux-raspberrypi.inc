DESCRIPTION = "Linux kernel for ${MACHINE}"
SECTION = "kernel"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=bbea815ee2795b2f4230826c0c6b8814"

PACKAGE_ARCH = "${MACHINE_ARCH}"

COMPATIBLE_MACHINE = "^(raspberrypi|raspberrypi0|raspberrypi2|raspberrypi3|raspberrypi4)$"

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI = "\
	https://github.com/raspberrypi/linux/archive/${SRCREV}.tar.gz \
	file://defconfig \
	file://${OPENVISION_BASE}/meta-openvision/recipes-linux/kernel-patches/kernel-add-support-for-gcc${VISIONGCCVERSION}.patch \
	"

# What we need from https://github.com/raspberrypi/linux/tree/rpi-5.4.y/arch/arm/configs
# DEFCONFIG_raspberrypi = "bcmrpi_defconfig"
# DEFCONFIG_raspberrypi0 = "bcmrpi_defconfig"
# DEFCONFIG_raspberrypi2 = "bcm2709_defconfig"
# DEFCONFIG_raspberrypi3 = "bcm2709_defconfig"
# DEFCONFIG_raspberrypi4 = "bcm2711_defconfig"
# For DVB drivers we could check https://github.com/LibreELEC/LibreELEC.tv/tree/master/projects/RPi/devices

KERNEL_EXTRA_ARGS_append_rpi = " DTC_FLAGS='-@ -H epapr'"

PE = "1"
PV = "${LINUX_VERSION}+git${SRCREV}"

inherit kernel machine_kernel_pr samba_change_dialect siteinfo

KCONFIG_MODE = "--alldefconfig"

LINUX_VERSION_EXTENSION = ""

# A LOADADDR is needed when building a uImage format kernel. This value is not
# set by default in rpi-4.8.y and later branches so we need to provide it
# manually. This value unused if KERNEL_IMAGETYPE is not uImage.
KERNEL_EXTRA_ARGS += "LOADADDR=0x00008000"

do_compile_append() {
    if [ "${SITEINFO_BITS}" = "64" ]; then
        cc_extra=$(get_cc_option)
        oe_runmake dtbs CC="${KERNEL_CC} $cc_extra " LD="${KERNEL_LD}" ${KERNEL_EXTRA_ARGS}
    fi
}

do_openvisiondefconfig() {
    install -m 0644 ${WORKDIR}/defconfig ${S}/arch/${ARCH}/configs/
    in_tree_defconfig="${WORKDIR}/defconfig"
}

addtask openvisiondefconfig before do_configure after do_unpack

do_rm_work() {
}
