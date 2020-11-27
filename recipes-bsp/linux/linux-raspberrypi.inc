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

# CMDLINE for raspberrypi
SERIAL = "${@oe.utils.conditional("ENABLE_UART", "1", "console=serial0,115200", "", d)}"
CMDLINE = "dwc_otg.lpm_enable=0 ${SERIAL} root=/dev/mmcblk0p2 rootfstype=ext4 rootwait"

# Add the kernel debugger over console kernel command line option if enabled
CMDLINE_append = ' ${@oe.utils.conditional("ENABLE_KGDB", "1", "kgdboc=serial0,115200", "", d)}'

# You can define CMDLINE_DEBUG as "debug" in your local.conf or distro.conf
# to enable kernel debugging.
CMDLINE_DEBUG = ""
CMDLINE_append = " ${CMDLINE_DEBUG}"

# A LOADADDR is needed when building a uImage format kernel. This value is not
# set by default in rpi-4.8.y and later branches so we need to provide it
# manually. This value unused if KERNEL_IMAGETYPE is not uImage.
KERNEL_EXTRA_ARGS += "LOADADDR=0x00008000"

# Set a variable in .configure
# $1 - Configure variable to be set
# $2 - value [n/y/value]
kernel_configure_variable() {
    # Remove the config
    CONF_SED_SCRIPT="$CONF_SED_SCRIPT /CONFIG_$1[ =]/d;"
    if test "$2" = "n"
    then
        echo "# CONFIG_$1 is not set" >> ${B}/.config
    else
        echo "CONFIG_$1=$2" >> ${B}/.config
    fi
}

config_setup() {
    # From kernel.bbclass. Unfortunately, this is needed to support builds that
    # use devtool. The reason is as follows:
    #
    # - In devtool builds, externalsrc.bbclass gets inherited and sets a list of
    # SRCTREECOVEREDTASKS, which don't get run because they affect the source
    # tree and, when using devtool, we want the developer's changes to be the
    # single source of truth. kernel-yocto.bbclass adds do_kernel_configme to
    # SRCTREECOVEREDTASKS, so it doesn't run in a devtool build., In a normal
    # non-devtool build, do_kernel_configme creates ${B}.config.
    #
    # - Normally (e.g. in linux-yocto), it would be OK that do_kernel_configme
    # doesn't run, because the first few lines of do_configure in kernel.bbclass
    # populate ${B}.config from either ${S}.config (if it exists) for custom
    # developer changes, or otherwise from ${WORDIR}/defconfig.
    #
    # - In linux-raspberrypi, we add do_configure_prepend, which tweaks
    # ${B}.config. Since this runs *before* the kernel.bbclass do_configure,
    # ${B}.config doesn't yet exist and we hit an error. Thus we need to move
    # the logic from do_configure up to before our do_configure_prepend. Because
    # we are copying only a portion of do_configure and not the whole thing,
    # there is no clean way to do it using OE functionality, so we just
    # copy-and-paste.
    if [ "${S}" != "${B}" ] && [ -f "${S}/.config" ] && [ ! -f "${B}/.config" ]; then
        mv "${S}/.config" "${B}/.config"
    fi

    # Copy defconfig to .config if .config does not exist. This allows
    # recipes to manage the .config themselves in do_configure_prepend().
    if [ -f "${WORKDIR}/defconfig" ] && [ ! -f "${B}/.config" ]; then
        cp "${WORKDIR}/defconfig" "${B}/.config"
    fi
}

do_configure_prepend() {
    config_setup

    mv -f ${B}/.config ${B}/.config.patched
    CONF_SED_SCRIPT=""

    if [ "${INITRAMFS_IMAGE_BUNDLE}" = "1" ]; then
        kernel_configure_variable OVERLAY_FS y
        kernel_configure_variable SQUASHFS y
        kernel_configure_variable UBIFS_FS y
    fi

    # Keep this the last line
    # Remove all modified configs and add the rest to .config
    sed -e "${CONF_SED_SCRIPT}" < '${B}/.config.patched' >> '${B}/.config'
    rm -f ${B}/.config.patched
}

do_compile_append() {
    if [ "${SITEINFO_BITS}" = "64" ]; then
        cc_extra=$(get_cc_option)
        oe_runmake dtbs CC="${KERNEL_CC} $cc_extra " LD="${KERNEL_LD}" ${KERNEL_EXTRA_ARGS}
    fi
}

do_deploy_append() {
    # Deploy cmdline.txt only for the main kernel package
    install -d ${DEPLOYDIR}/${BOOTFILES_DIR_NAME}
    echo "${CMDLINE}${PITFT_PARAMS}" > ${DEPLOYDIR}/${BOOTFILES_DIR_NAME}/cmdline.txt
}

do_openvisiondefconfig() {
    install -m 0644 ${WORKDIR}/defconfig ${S}/arch/${ARCH}/configs/
    in_tree_defconfig="${WORKDIR}/defconfig"
}

addtask openvisiondefconfig before do_configure after do_unpack

do_rm_work() {
}
