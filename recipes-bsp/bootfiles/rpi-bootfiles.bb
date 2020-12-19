DESCRIPTION = "Closed source binary files to help boot the ARM on RPi."
LICENSE = "Proprietary"

LIC_FILES_CHKSUM = "file://LICENCE.broadcom;md5=4a4d169737c0786fb9482bb6d30401d1"

inherit deploy nopackages

include raspberrypi-firmware.inc

INHIBIT_DEFAULT_DEPS = "1"

DEPENDS = "rpi-config rpi-cmdline"

COMPATIBLE_MACHINE = "^(raspberrypi|raspberrypi0|raspberrypi2|raspberrypi3|raspberrypi4)$"

S = "${RPIFW_S}/boot"

do_deploy() {
    install -d ${DEPLOYDIR}/${BOOTFILES_DIR_NAME}

    for i in ${S}/*.elf ; do
        cp -f $i ${DEPLOYDIR}/${BOOTFILES_DIR_NAME}
    done
    for i in ${S}/*.dat ; do
        cp -f $i ${DEPLOYDIR}/${BOOTFILES_DIR_NAME}
    done
    for i in ${S}/*.bin ; do
        cp -f $i ${DEPLOYDIR}/${BOOTFILES_DIR_NAME}
    done

    # Add stamp in deploy directory
    touch ${DEPLOYDIR}/${BOOTFILES_DIR_NAME}/${BOOTFILES_DIR_NAME}-${PV}.stamp
}

do_deploy[depends] += "rpi-config:do_deploy rpi-cmdline:do_deploy"

addtask deploy before do_build after do_install

do_deploy[dirs] += "${DEPLOYDIR}/${BOOTFILES_DIR_NAME}"

PACKAGE_ARCH = "${MACHINE_ARCH}"
