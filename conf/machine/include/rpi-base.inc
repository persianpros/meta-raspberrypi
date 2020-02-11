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

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	rpi-brcm-firmwares \
	rpi-dvb-modules-e2procfs \
	kernel-module-e2-procfs \
	rpi-dvbsoftwareca \
	kernel-module-dvbsoftwareca \
	kernel-modules \
	${@bb.utils.contains("MACHINE_FEATURES", "nolcd", "", "enigma2-plugin-extensions-lcd4linux", d)} \
	lirc \
	lirc-plugins \
"

KERNEL_MODULE_AUTOLOAD += "\
	brcmfmac \
	bcm2835-v4l2 \
	em28xx-v4l \
	dvb-core \
	dvb-usb \
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

MACHINE_FEATURES += "apm usbhost keyboard vfat ext2 alsa bluetooth sdio satip rpi-vision"

# Raspberry Pi has no hardware clock
MACHINE_FEATURES_BACKFILL_CONSIDERED = "rtc"

MACHINE_EXTRA_RRECOMMENDS += " udev-rules-rpi"

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
