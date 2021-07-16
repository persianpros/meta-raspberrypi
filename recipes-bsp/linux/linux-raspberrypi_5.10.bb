require linux-raspberrypi.inc

LINUX_VERSION = "${KERNELVERSION}"

SRCREV = "e6410afca8c583d84538bf84d03ccf9a774f8fcf"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "b29733fc9d578811d94cf2f717dd3b96"
SRC_URI[sha256sum] = "53015135264f0717f32312ec1b249485f85de93f23728be7b73cd55a3bfac35c"
