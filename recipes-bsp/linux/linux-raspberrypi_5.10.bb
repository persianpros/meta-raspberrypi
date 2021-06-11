require linux-raspberrypi.inc

LINUX_VERSION = "${KERNELVERSION}"

SRCREV = "6b0f228ba15ade487ed4adc50fb7f460195c38db"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "bedd1713d90eab1fd232b558bdbb5e84"
SRC_URI[sha256sum] = "550a1c1cd0aeaaa6a891a12169d8b51e086e22152399a7a67e7c1951cc2fef48"
