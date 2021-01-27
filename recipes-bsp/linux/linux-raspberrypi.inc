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
	file://0001-Add-Silicon-Labs-SI2183.patch \
	file://0002-Add-Airoha-Technology-AV201x.patch \
	file://0003-Add-TBS-5520SE.patch \
	file://0001-Add-linux-version.h-and-update-uapi-frontends.h.patch \
	file://0002-Update-dvb_frontend.h.patch \
	file://0001-Update-dvb-usb.h-and-uapi-frontend.h.patch \
	file://0001-Register-and-unregister-second-frontend-for-dvb-s.patch \
	"

# What we need from https://github.com/raspberrypi/linux/tree/rpi-5.10.y/arch/arm/configs
# DEFCONFIG_raspberrypi = "bcmrpi_defconfig"
# DEFCONFIG_raspberrypi0 = "bcmrpi_defconfig"
# DEFCONFIG_raspberrypi2 = "bcm2709_defconfig"
# DEFCONFIG_raspberrypi3 = "bcm2709_defconfig"
# DEFCONFIG_raspberrypi4 = "bcm2711_defconfig"
# For DVB drivers we could check https://github.com/LibreELEC/LibreELEC.tv/tree/master/projects/RPi/devices

KERNEL_DTC_FLAGS += "-@ -H epapr"

PE = "1"
PV = "${LINUX_VERSION}+git${SRCREV}"

inherit kernel machine_kernel_pr samba_change_dialect siteinfo

KCONFIG_MODE = "--alldefconfig"

LINUX_VERSION_EXTENSION = ""

# A LOADADDR is needed when building a uImage format kernel. This value is not
# set by default in rpi-4.8.y and later branches so we need to provide it
# manually. This value unused if KERNEL_IMAGETYPE is not uImage.
KERNEL_EXTRA_ARGS += "LOADADDR=0x00008000"

do_openvisiondefconfig() {
    install -m 0644 ${WORKDIR}/defconfig ${S}/arch/${ARCH}/configs/
    in_tree_defconfig="${WORKDIR}/defconfig"
}

addtask openvisiondefconfig before do_configure after do_unpack

do_rm_work() {
}
