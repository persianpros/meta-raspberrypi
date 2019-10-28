BOX_BRAND = "rpi"

PREFERRED_PROVIDER_virtual/kernel ?= "linux-raspberrypi"
PREFERRED_VERSION_linux-raspberrypi ?= "4.19.%"
PREFERRED_PROVIDER_virtual/egl ?= "userland"
PREFERRED_PROVIDER_virtual/libgles2 ?= "userland"
PREFERRED_PROVIDER_jpeg ?= "jpeg"

HDMI_IGNORE_EDID = "0xa5000080"
DISABLE_OVERSCAN = "1"
HDMI_DRIVE = "2"
HDMI_FORCE_HOTPLUG = "1"
SDTV_MODE = "2"
SDTV_ASPECT = "3"
DISABLE_FW_KMS = "1"

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
	overlays/dwc2.dtbo \
	overlays/gpio-key.dtbo \
	overlays/i2c-rtc.dtbo \
	overlays/miniuart-bt.dtbo \
	overlays/pps-gpio.dtbo \
	overlays/rpi-ft5406.dtbo \
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
KERNEL_IMAGETYPE_DIRECT ??= "zImage"
KERNEL_IMAGETYPE ??= "zImage"

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


IMAGE_BOOT_FILES ?= "rpi-bootfiles/* \
                 ${@make_dtb_boot_files(d)} \
                 ${KERNEL_IMAGETYPE};${SDIMG_KERNELIMAGE} \
                 "
do_image_wic[depends] += " \
    rpi-bootfiles:do_deploy \
    "

do_image_wic[recrdeps] = "do_build"

# The kernel image is installed into the FAT32 boot partition and does not need
# to also be installed into the rootfs.
RDEPENDS_${KERNEL_PACKAGE_NAME}-base = ""
