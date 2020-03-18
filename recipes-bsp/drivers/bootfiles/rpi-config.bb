DESCRIPTION = "Commented config.txt file for the Raspberry Pi. \
               The Raspberry Pi config.txt file is read by the GPU before \
               the ARM core is initialised. It can be used to set various \
               system configuration parameters."
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

COMPATIBLE_MACHINE = "^(raspberrypi|raspberrypi0|raspberrypi2|raspberrypi3|raspberrypi4)$"

SRC_URI = "file://config.txt"

S = "${WORKDIR}"

INHIBIT_DEFAULT_DEPS = "1"

inherit deploy nopackages

do_deploy() {
    install -d ${DEPLOYDIR}/rpi-bootfiles

    cp ${S}/config.txt ${DEPLOYDIR}/rpi-bootfiles/

    if [ -n "${KEY_DECODE_MPG2}" ]; then
        sed -i '/#decode_MPG2=/ c\decode_MPG2=${KEY_DECODE_MPG2}' ${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi
    if [ -n "${KEY_DECODE_WVC1}" ]; then
        sed -i '/#decode_WVC1=/ c\decode_WVC1=${KEY_DECODE_WVC1}' ${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi
    if [ -n "${DISABLE_OVERSCAN}" ]; then
        sed -i '/#disable_overscan=/ c\disable_overscan=${DISABLE_OVERSCAN}' ${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi
    if [ "${DISABLE_SPLASH}" = "1" ]; then
        sed -i '/#disable_splash=/ c\disable_splash=${DISABLE_SPLASH}' ${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi

    # Set overclocking options
    if [ -n "${ARM_FREQ}" ]; then
        sed -i '/#arm_freq=/ c\arm_freq=${ARM_FREQ}' ${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi
    if [ -n "${GPU_FREQ}" ]; then
        sed -i '/#gpu_freq=/ c\gpu_freq=${GPU_FREQ}' ${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi
    if [ -n "${CORE_FREQ}" ]; then
        sed -i '/#core_freq=/ c\core_freq=${CORE_FREQ}' ${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi
    if [ -n "${SDRAM_FREQ}" ]; then
        sed -i '/#sdram_freq=/ c\sdram_freq=${SDRAM_FREQ}' ${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi
    if [ -n "${OVER_VOLTAGE}" ]; then
        sed -i '/#over_voltage=/ c\over_voltage=${OVER_VOLTAGE}' ${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi

    # GPU memory
    if [ -n "${GPU_MEM}" ]; then
        sed -i '/#gpu_mem=/ c\gpu_mem=${GPU_MEM}' ${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi
    if [ -n "${GPU_MEM_256}" ]; then
        sed -i '/#gpu_mem_256=/ c\gpu_mem_256=${GPU_MEM_256}' ${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi
    if [ -n "${GPU_MEM_512}" ]; then
        sed -i '/#gpu_mem_512=/ c\gpu_mem_512=${GPU_MEM_512}' ${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi
    if [ -n "${GPU_MEM_1024}" ]; then
        sed -i '/#gpu_mem_1024=/ c\gpu_mem_1024=${GPU_MEM_1024}' ${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi

    # Set boot delay
    if [ -n "${BOOT_DELAY}" ]; then
        sed -i '/#boot_delay=/ c\boot_delay=${BOOT_DELAY}' ${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi
    if [ -n "${BOOT_DELAY_MS}" ]; then
        sed -i '/#boot_delay_ms=/ c\boot_delay_ms=${BOOT_DELAY_MS}' ${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi

    # Set HDMI and composite video options
    if [ -n "${HDMI_SAFE_MODE}" ]; then
        sed -i '/#hdmi_safe=/ c\hdmi_safe=${HDMI_SAFE_MODE}' ${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi
    if [ -n "${HDMI_IGNORE_EDID}" ]; then
        sed -i '/#hdmi_ignore_edid=/ c\hdmi_ignore_edid=${HDMI_IGNORE_EDID}' ${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi
    if [ -n "${DISABLE_FW_KMS}" ]; then
        sed -i '/#disable_fw_kms_setup=/ c\disable_fw_kms_setup=${DISABLE_FW_KMS}' ${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi
    if [ -n "${HDMI_FORCE_HOTPLUG}" ]; then
        sed -i '/#hdmi_force_hotplug=/ c\hdmi_force_hotplug=${HDMI_FORCE_HOTPLUG}' ${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi
    if [ -n "${HDMI_DRIVE}" ]; then
        sed -i '/#hdmi_drive=/ c\hdmi_drive=${HDMI_DRIVE}' ${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi
    if [ -n "${HDMI_GROUP}" ]; then
        sed -i '/#hdmi_group=/ c\hdmi_group=${HDMI_GROUP}' ${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi
    if [ -n "${HDMI_MODE}" ]; then
        sed -i '/#hdmi_mode=/ c\hdmi_mode=${HDMI_MODE}' ${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi
    if [ -n "${CONFIG_HDMI_BOOST}" ]; then
        sed -i '/#config_hdmi_boost=/ c\config_hdmi_boost=${CONFIG_HDMI_BOOST}' ${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi
    if [ -n "${SDTV_MODE}" ]; then
        sed -i '/#sdtv_mode=/ c\sdtv_mode=${SDTV_MODE}' ${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi
    if [ -n "${SDTV_ASPECT}" ]; then
        sed -i '/#sdtv_aspect=/ c\sdtv_aspect=${SDTV_ASPECT}' ${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi
    if [ -n "${DISPLAY_ROTATE}" ]; then
        sed -i '/#display_rotate=/ c\display_rotate=${DISPLAY_ROTATE}' ${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi

    # Offline compositing support
    if [ "${DISPMANX_OFFLINE}" = "1" ]; then
        echo "# Enable offline compositing" >>${DEPLOYDIR}/rpi-bootfiles/config.txt
        echo "dispmanx_offline=1" >>${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi

    # SPI bus support
    if [ "${ENABLE_SPI_BUS}" = "1" ]; then
        echo "# Enable SPI bus" >>${DEPLOYDIR}/rpi-bootfiles/config.txt
        echo "dtparam=spi=on" >>${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi

    # I2C support
    if [ "${ENABLE_I2C}" = "1" ]; then
        echo "# Enable I2C" >>${DEPLOYDIR}/rpi-bootfiles/config.txt
        echo "dtparam=i2c1=on" >>${DEPLOYDIR}/rpi-bootfiles/config.txt
        echo "dtparam=i2c_arm=on" >>${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi

    # UART support
    if [ "${ENABLE_UART}" = "1" ]; then
        echo "# Enable UART" >>${DEPLOYDIR}/rpi-bootfiles/config.txt
        echo "enable_uart=1" >>${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi

    # DWC2 USB peripheral support
    if [ "${ENABLE_DWC2_PERIPHERAL}" = "1" ]; then
        echo "# Enable USB peripheral mode" >> ${DEPLOYDIR}/rpi-bootfiles/config.txt
        echo "dtoverlay=dwc2,dr_mode=peripheral" >> ${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi

    # ENABLE CAN
    if [ "${ENABLE_CAN}" = "1" ]; then
        echo "# Enable CAN" >>${DEPLOYDIR}/rpi-bootfiles/config.txt
        echo "dtoverlay=mcp2515-can0,oscillator=16000000,interrupt=25" >>${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi

    # ENABLE RPI TV HAT
    if [ "${ENABLE_RPI_TV}" = "1" ]; then
        echo "# Enable RPI TV HAT" >>${DEPLOYDIR}/rpi-bootfiles/config.txt
        echo "dtoverlay=rpi-tv" >>${DEPLOYDIR}/rpi-bootfiles/config.txt
    fi

    # Append extra config if the user has provided any
    printf "${RPI_EXTRA_CONFIG}\n" >> ${DEPLOYDIR}/rpi-bootfiles/config.txt
}

addtask deploy before do_build after do_install
do_deploy[dirs] += "${DEPLOYDIR}/rpi-bootfiles"

PACKAGE_ARCH = "${MACHINE_ARCH}"
