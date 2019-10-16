BOX_BRAND = "rpi"

PREFERRED_PROVIDER_virtual/kernel ?= "linux-raspberrypi"
PREFERRED_VERSION_linux-raspberrypi ?= "4.19.%"
PREFERRED_PROVIDER_virtual/egl ?= "userland"
PREFERRED_PROVIDER_virtual/libgles2 ?= "userland"
PREFERRED_PROVIDER_jpeg ?= "jpeg"

IMAGE_CLASSES += "sdcard_image-rpi"

SOC_FAMILY = "rpi"
include conf/machine/include/soc-family.inc

IMAGE_FSTYPES ?= "rpi-sdimg"
WKS_FILE ?= "sdimage-raspberrypi.wks"

DVBMEDIASINK_CONFIG = "--with-wmv --with-pcm --with-eac3 --with-h265 --with-dtsdownmix"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	rpi-dvb-modules-e2procfs \
	kernel-module-e2-procfs \
	rpi-dvbsoftwareca \
	kernel-module-dvbsoftwareca \
	kernel-module-gpio-ir-tx \
	kernel-module-gpio-ir-recv \
	${RPI_DVB_MODULES} \
	liborc-0.4-0 \
	orc \
	fribidi \
	omxplayer \
	libcec \
	enigma2-plugin-extensions-lcd4linux \
"

RPI_DVB_MODULES = "\
	kernel-module-cx231xx-dvb \
	kernel-module-dvb-as102 \
	kernel-module-dvb-core \
	kernel-module-dvb-pll \
	kernel-module-dvb-usb \
	kernel-module-dvb-usb-a800 \
	kernel-module-dvb-usb-af9005 \
	kernel-module-dvb-usb-af9015 \
	kernel-module-dvb-usb-af9035 \
	kernel-module-dvb-usb-anysee \
	kernel-module-dvb-usb-au6610 \
	kernel-module-dvb-usb-az6007 \
	kernel-module-dvb-usb-az6027 \
	kernel-module-dvb-usb-ce6230 \
	kernel-module-dvb-usb-cinergyt2 \
	kernel-module-dvb-usb-cxusb \
	kernel-module-dvb-usb-dib0700 \
	kernel-module-dvb-usb-dibusb-common \
	kernel-module-dvb-usb-dibusb-mb \
	kernel-module-dvb-usb-dibusb-mc \
	kernel-module-dvb-usb-dibusb-mc-common \
	kernel-module-dvb-usb-digitv \
	kernel-module-dvb-usb-dtt200u \
	kernel-module-dvb-usb-dtv5100 \
	kernel-module-dvb-usb-dvbsky \
	kernel-module-dvb-usb-dw2102 \
	kernel-module-dvb-usb-ec168 \
	kernel-module-dvb-usb-gl861 \
	kernel-module-dvb-usb-gp8psk \
	kernel-module-dvb-usb-lmedm04 \
	kernel-module-dvb-usb-m920x \
	kernel-module-dvb-usb-mxl111sf \
	kernel-module-dvb-usb-nova-t-usb2 \
	kernel-module-dvb-usb-opera \
	kernel-module-dvb-usb-pctv452e \
	kernel-module-dvb-usb-rtl28xxu \
	kernel-module-dvb-usb-technisat-usb2 \
	kernel-module-dvb-usb-ttusb2 \
	kernel-module-dvb-usb-umt-010 \
	kernel-module-dvb-usb-v2 \
	kernel-module-dvb-usb-vp702x \
	kernel-module-dvb-usb-vp7045 \
	kernel-module-em28xx-dvb \
	kernel-module-smsdvb \
	kernel-module-tm6000-dvb \
"

KERNEL_MODULE_AUTOLOAD += "\
	gpio-ir-tx \
	gpio-ir-recv \
"

RPI_KERNEL_DEVICETREE_OVERLAYS = "\
	overlays/dwc-otg.dtbo \
	overlays/gpio-key.dtbo \
	overlays/miniuart-bt.dtbo \
	overlays/pps-gpio.dtbo \
	overlays/rpi-poe.dtbo \
	overlays/w1-gpio-pullup.dtbo \
	overlays/w1-gpio.dtbo \
	overlays/gpio-ir-tx.dtbo \
	overlays/gpio-ir.dtbo \
	overlays/rpi-tv.dtbo \
	overlays/gpio-fan.dtbo \
"

KERNEL_DEVICETREE ?= " \
	${RPI_KERNEL_DEVICETREE} \
	${RPI_KERNEL_DEVICETREE_OVERLAYS} \
"

# By default:
#
# * When u-boot is disabled use the "Image" format which can be directly loaded
#   by the rpi firmware.
#
# * When u-boot is enabled use the "uImage" format and the "bootm" command
#   within u-boot to load the kernel.
KERNEL_BOOTCMD ??= "bootm"
KERNEL_IMAGETYPE_UBOOT ??= "uImage"
KERNEL_IMAGETYPE_DIRECT ??= "zImage"
KERNEL_IMAGETYPE ?= "${@bb.utils.contains('RPI_USE_U_BOOT', '1', \
        '${KERNEL_IMAGETYPE_UBOOT}', '${KERNEL_IMAGETYPE_DIRECT}', d)}"

MACHINE_FEATURES += "apm usbhost keyboard vfat ext2 alsa bluetooth sdio rpi-vision"

# Raspberry Pi has no hardware clock
MACHINE_FEATURES_BACKFILL_CONSIDERED = "rtc"

MACHINE_EXTRA_RRECOMMENDS += " kernel-modules udev-rules-rpi"

# Set Raspberrypi splash image
SPLASH = "psplash-raspberrypi"

def make_dtb_boot_files(d):
    # Generate IMAGE_BOOT_FILES entries for device tree files listed in
    # KERNEL_DEVICETREE.
    alldtbs = d.getVar('KERNEL_DEVICETREE')
    imgtyp = d.getVar('KERNEL_IMAGETYPE')

    def transform(dtb):
        base = os.path.basename(dtb)
        if dtb.endswith('dtb'):
            # eg: whatever/bcm2708-rpi-b.dtb has:
            #     DEPLOYDIR file: bcm2708-rpi-b.dtb
            #     destination: bcm2708-rpi-b.dtb
            return base
        elif dtb.endswith('dtbo'):
            # overlay dtb:
            # eg: overlays/hifiberry-amp.dtbo has:
            #     DEPLOYDIR file: hifiberry-amp.dtbo
            #     destination: overlays/hifiberry-amp.dtbo
            return '{};{}'.format(base, dtb)

    return ' '.join([transform(dtb) for dtb in alldtbs.split(' ') if dtb])


IMAGE_BOOT_FILES ?= "bcm2835-bootfiles/* \
                 ${@make_dtb_boot_files(d)} \
                 ${@bb.utils.contains('RPI_USE_U_BOOT', '1', \
                    '${KERNEL_IMAGETYPE} u-boot.bin;${SDIMG_KERNELIMAGE} boot.scr', \
                    '${KERNEL_IMAGETYPE};${SDIMG_KERNELIMAGE}', d)} \
                 "
do_image_wic[depends] += " \
    bcm2835-bootfiles:do_deploy \
    ${@bb.utils.contains('RPI_USE_U_BOOT', '1', 'u-boot:do_deploy', '',d)} \
    "

do_image_wic[recrdeps] = "do_build"

# The kernel image is installed into the FAT32 boot partition and does not need
# to also be installed into the rootfs.
RDEPENDS_${KERNEL_PACKAGE_NAME}-base = ""
